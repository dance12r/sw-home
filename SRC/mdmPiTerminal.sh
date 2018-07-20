#!/bin/bash

cd ~/
git clone https://github.com/dance12r/mdmPiTerminal
cd mdmPiTerminal
sudo chmod +x scripts/mdm-pi-installer.sh
./scripts/mdm-pi-installer.sh

sudo chmod +x systemd/service-installer.sh
sudo ./systemd/service-installer.sh

sudo systemctl enable mdmpiterminal.service
sudo systemctl enable mdmpiterminalsayreply.service

sudo systemctl start mdmpiterminalsayreply.service
sudo systemctl start mdmpiterminal.service

exit 0
