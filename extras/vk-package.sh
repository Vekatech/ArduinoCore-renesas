#!/bin/bash

VERSION=$1

if [ ! -f platform.txt ]; then
  echo Launch this script from the root core folder as ./extras/package.sh
  exit 2
fi

if [ ! -d ../ArduinoCore-API ]; then
  git clone https://github.com/arduino/ArduinoCore-API.git ../ArduinoCore-API
fi

echo $VERSION

EXCLUDE_TAGS="--exclude-tag-all=.portenta_only --exclude-tag-all=.unor4_only"
mv variants/VK_NANOR4/.unor4_only variants/VK_NANOR4/.vk_only
mv variants/VK_RA4M2_NANO/.unor4_only variants/VK_RA4M2_NANO/.vk_only
mv variants/VK_RA4M2_FEMTO/.unor4_only variants/VK_RA4M2_FEMTO/.vk_only

FILENAME=ArduinoCore-renesas_$VERSION.tar.bz2

git checkout boards.txt
git checkout platform.txt

sed -n '/### VK Boards ###/,/### VK Boards END ###/p' boards.txt > vk-boards.txt
mv vk-boards.txt boards.txt
sed -i 's/Arduino Renesas fsp Boards/VK Boards/g' platform.txt

CORE_BASE=`basename $PWD`
cd ..
tar $EXCLUDE_TAGS --exclude='*.vscode*' --exclude='*.tar.*' --exclude='*.json*' --exclude='*.git*' --exclude='*e2studio*' --exclude='*extras*' -cjhvf $FILENAME $CORE_BASE
cd -

mv variants/VK_NANOR4/.vk_only variants/VK_NANOR4/.unor4_only
mv variants/VK_RA4M2_NANO/.vk_only variants/VK_RA4M2_NANO/.unor4_only
mv variants/VK_RA4M2_FEMTO/.vk_only variants/VK_RA4M2_FEMTO/.unor4_only
mv ../$FILENAME .

CHKSUM=`sha256sum $FILENAME | awk '{ print $1 }'`
SIZE=`wc -c $FILENAME | awk '{ print $1 }'`

cat extras/vk-package_index.json.template |
sed "s/%%VERSION%%/${VERSION}/" |
sed "s/%%FILENAME_UNO%%/${FILENAME}/" |
sed "s/%%CHECKSUM_UNO%%/${CHKSUM}/" |
sed "s/%%SIZE_UNO%%/${SIZE}/" > package_vekatech_index.json

echo
echo "Generating:"
echo "  $FILENAME"
echo "  package_vekatech_index.json"
echo

git checkout boards.txt
git checkout platform.txt