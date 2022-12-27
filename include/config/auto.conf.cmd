deps_config := \
	common/Kconfig \
	lib/Kconfig \
	board/grx500/Kconfig \
	board/vbg400/Kconfig \
	board/ar10/Kconfig \
	board/hn1/Kconfig \
	board/vr9/Kconfig \
	board/amazon_se/Kconfig \
	board/danube/Kconfig \
	board/ar9/Kconfig \
	scripts_platform/Kconfig \
	Kconfig

include/config/auto.conf: \
	$(deps_config)


$(deps_config): ;
