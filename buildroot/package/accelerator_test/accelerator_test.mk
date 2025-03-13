################################################################################
#
# test_accelerator package
#
################################################################################

ACCELERATOR_TEST_VERSION = 1.0
ACCELERATOR_TEST_SITE = package/accelerator_test/src
ACCELERATOR_TEST_SITE_METHOD = local

define ACCELERATOR_TEST_BUILD_CMDS
	$(MAKE) CC="$(TARGET_CC)" LD="$(TARGET_LD)" -C $(@D)
endef

define ACCELERATOR_TEST_INSTALL_TARGET_CMDS
	$(INSTALL) -D -m 0755 $(@D)/test_accelerator $(TARGET_DIR)/usr/bin
endef

$(eval $(generic-package))

