#!/usr/bin/bash

PATH_CDS_BUF=$(cd $(dirname `dirname $0`);pwd)
export PATH_CDS=$PATH_CDS_BUF
chmod 666 /etc/profile
echo "export PATH_CDS=$PATH_CDS_BUF" >> /etc/profile
chmod 644 /etc/profile
echo "PATH_CDS_BUF = $PATH_CDS_BUF"
