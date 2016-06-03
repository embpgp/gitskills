#platform-specs.mk
#
#
#

$(foreach specfile, $(PLATFROM_SPECS), $(eval -include $(specfile)))
