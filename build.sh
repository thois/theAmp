#!/bin/bash
vst_version="vstsdk365_12_11_2015_build_67"

echo "Downloading libs"
if [ ! -d "Libs" ]; then
	mkdir Libs
fi
pushd Libs
if [ ! -f ${vst_version}.zip ]; then
	wget http://www.steinberg.net/sdk_downloads/${vst_version}.zip
fi
if [ ! -f juce-grapefruit-linux.zip ]; then
	wget http://assets.roli.com/juce/juce-grapefruit-linux.zip
fi
echo "Unzipping libs"
if [ ! -d "juce" ]; then
	mkdir juce
fi
unzip -q ${vst_version}.zip
unzip -q -d juce juce-grapefruit-linux.zip
popd
echo "Building theAmp"
pushd Builds/Linux
make -j4
popd
popd
echo "All done, run use \"Builds/Linux/build.theAmp.so\" as VST plugin"
