################################################################################
#
# accelerator package
#
################################################################################

ACCELERATOR_VERSION = 1.0.0
ACCELERATOR_SITE = package/accelerator/src
ACCELERATOR_SITE_METHOD = local
ACCELERATOR_LICENSE = GPL-2.0

$(eval $(kernel-module))
$(eval $(generic-package))

