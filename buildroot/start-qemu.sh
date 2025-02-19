#!/bin/sh

# BINARIES_DIR="${0%/*}/"
BINARIES_DIR="./output/images/"
# shellcheck disable=SC2164

mode_serial=false
mode_sys_qemu=false
while [ "$1" ]; do
    case "$1" in
    --serial-only|serial-only) mode_serial=true; shift;;
    --use-system-qemu) mode_sys_qemu=true; shift;;
    --) shift; break;;
    *) echo "unknown option: $1" >&2; exit 1;;
    esac
done

if ${mode_serial}; then
    EXTRA_ARGS='-nographic'
else
    EXTRA_ARGS=''
fi

if ! ${mode_sys_qemu}; then
    export PATH="$(realpath $(dirname $(pwd)))/qemu/build/:${PATH}"
fi

cd "${BINARIES_DIR}"
#se non funziona, runna rootfs.ext2
exec qemu-system-aarch64 \
    -M virt -cpu cortex-a53 \
    -D qemu-debug.log -d guest_errors \
    -nographic -smp 1 \
    -kernel Image -append "rootwait root=/dev/vda console=ttyAMA0" \
    -netdev user,id=eth0 -device virtio-net-device,netdev=eth0 \
    -drive file=rootfs.ext4,if=none,format=raw,id=hd0 \
    -device virtio-blk-device,drive=hd0 \
    ${EXTRA_ARGS} "$@"

