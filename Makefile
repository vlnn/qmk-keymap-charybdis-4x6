##
# Deploy and compile the keymap via qmk_firmware environment
#

.DEFAULT_GOAL := help
QMKDIR :=  ~/src/qmk_firmware
QMKPATH := keyboards/bastardkb/charybdis/4x6/keymaps
AVRPORT := /dev/tty.usbmodem21201

compile: ## Deploy the 'vlnn' keymap top qmk_firmware repo and compile it into the firmware of hex format
	@echo "Deploying the \'vlnn\' keymap into $(QMKDIR):"
	rsync -arupE vlnn $(QMKDIR)/$(QMKPATH)
	@echo "Compiling the firmware"
	qmk compile
	@echo "Copying all the firmwares to active directory"
	rsync -arupE $(QMKDIR)/*.hex ./
	@echo "Look for the latest firmware:"
	ls ./bastardkb_charybdis_4x6_v2_elitec_vlnn.hex
# end

flash: ## Flash the \'vlnn\' keymap: ensure you plug your keyboard in boot mode first
	avrdude -p ATmega32U4 -c avr109 -P $(AVRPORT) -b 57600 -U flash:w:bastardkb_charybdis_4x6_v2_elitec_vlnn.hex:i
# end

help:   ## Show short help for every available make target
	@echo "\033[1mAvailable make commands with descriptions:"
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[1m\033[32mmake %-30s\033[0m %s\n", $$1, $$2}'
	@echo "For more specific info check https://github.com/vlnn/README.md"
