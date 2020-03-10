This is an installation guide on how to install NRFTools on linux

NRFTools requires that the J-Link Software and Documentation Pack is installed.
It can be installed with the provided JLink_Linux packages, or downloaded from https://www.segger.com/downloads/jlink.

Install NRFTools with deb package:
sudo dpkg -i --force-overwrite nRFTools_<version_number>_Linux.deb
Or open with your preferred package manager.

Install NRFTools with tarball:
1) Copy the folders nrfjprog and mergehex to /opt

2) Make symbolic link for nrfjprog in /usr/bin/local
	sudo ln -s /opt/nrfjprog/nrfjprog /usr/bin/local/nrfjprog

3) Make symbolic link for mergehex in /usr/bin/local
	sudo ln -s /opt/mergehex/mergehex /usr/bin/local/mergehex
