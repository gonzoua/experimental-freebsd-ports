--- include/configs/embestmx6boards.h.orig	2015-04-13 07:53:03.000000000 -0700
+++ include/configs/embestmx6boards.h	2015-11-12 13:16:39.587303000 -0800
@@ -13,6 +13,9 @@
 #ifndef __RIOTBOARD_CONFIG_H
 #define __RIOTBOARD_CONFIG_H
 
+#define CONFIG_SYS_DCACHE_OFF
+#define CONFIG_SYS_L2CACHE_OFF
+
 #include <asm/arch/imx-regs.h>
 #include <asm/imx-common/gpio.h>
 
@@ -232,4 +235,60 @@
 	"fdtfile=" CONFIG_FDTFILE "\0" \
 	BOOTENV
 
+/*****************************************************************************
+ * FreeBSD customizations from here down.
+ ****************************************************************************/
+#define CONFIG_API
+#define CONFIG_CMD_ELF
+#define CONFIG_CMD_ENV_EXISTS
+
+#undef  CONFIG_CMD_BMODE
+#define CONFIG_CMD_BMODE
+
+#undef  CONFIG_SYS_MMC_MAX_DEVICE
+#define CONFIG_SYS_MMC_MAX_DEVICE CONFIG_SYS_FSL_USDHC_NUM
+
+#undef  CONFIG_LOADADDR
+#define CONFIG_LOADADDR 	0x11000000
+
+/* Create a small(ish) boot environment for FreeBSD. */
+#undef  CONFIG_EXTRA_ENV_SETTINGS
+#define CONFIG_EXTRA_ENV_SETTINGS \
+	"loadaddr=0x11000000\0" \
+	\
+	"Fatboot=" \
+	  "env exists loaderdev || env set loaderdev ${fatdev}; " \
+	  "env exists UserFatboot && run UserFatboot; " \
+	  "echo Booting from: ${fatdev} ${bootfile}; " \
+	  "fatload ${fatdev} ${loadaddr} ${bootfile} && bootelf; " \
+	"\0" \
+	"Netboot=" \
+	  "env exists loaderdev || env set loaderdev net; " \
+	  "env exists UserNetboot && run UserNetboot; " \
+	  "dhcp ${loadaddr} ${bootfile} && bootelf; " \
+	"\0" \
+	"Preboot=" \
+	  "env exists bootfile || bootfile=ubldr; " \
+	  "env exists uenv_file || uenv_file=uEnv.txt; " \
+	  "env exists SetupFdtfile && run SetupFdtfile; " \
+	  "env exists SetupFatdev && run SetupFatdev; " \
+	  "env exists SetupUenv && run SetupUenv; " \
+	  "env exists UserPreboot && run UserPreboot; " \
+	"\0" \
+	"SetupFdtfile=" \
+	  "env exists fdt_file || env set fdt_file ${fdt_soc}-${fdt_board}.dtb" \
+	"\0" \
+	"SetupFatdev=" \
+	  "env exists fatdev || fatdev='mmc 0'; " \
+	"\0" \
+	"SetupUenv=" \
+	  "fatload ${fatdev} ${loadaddr} ${uenv_file} && " \
+	    "env import -t ${loadaddr} ${filesize}; " \
+	"\0"
+
+#undef  CONFIG_BOOTCOMMAND
+#define CONFIG_BOOTCOMMAND	"run Fatboot"
+#undef  CONFIG_PREBOOT
+#define CONFIG_PREBOOT		"run Preboot"
+
 #endif                         /* __RIOTBOARD_CONFIG_H */
