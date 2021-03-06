#!/usr/bin/env bash

shopt -s -o nounset

echo "testing solvers using binaries and libraries in build-linux64-server/bin and tests in testFiles"

projectDir=/vagrant_numerics

solverDir="${projectDir}/build-linux64-server/bin"
inputDir="${projectDir}/testFiles/input"
workDir="${projectDir}/testFiles/working"
archiveDir="${projectDir}/testFiles/archive/linux64-server"

mkdir -p $workDir
mkdir -p $archiveDir

cd $projectDir

#
# Test FiniteVolume_x64
#
mkdir -p ${workDir}/FiniteVolume
rm ${workDir}/FiniteVolume/*
cp ${inputDir}/FiniteVolume/SimID_11538992_0_* ${workDir}/FiniteVolume
${solverDir}/FiniteVolume_x64 ${workDir}/FiniteVolume/SimID_11538992_0_.fvinput

mkdir -p ${archiveDir}/FiniteVolume
cp ${workDir}/FiniteVolume/SimID_11538992_0_*  ${archiveDir}/FiniteVolume
rm ${workDir}/FiniteVolume/*

#
# Test MovingBoundary_x64
#
mkdir -p ${workDir}/MovingBoundary
rm ${workDir}/MovingBoundary/*
cp ${inputDir}/MovingBoundary/SimID_599489767_0_* ${workDir}/MovingBoundary
${solverDir}/MovingBoundary_x64 --config ${workDir}/MovingBoundary/SimID_599489767_0_mb.xml

mkdir -p ${archiveDir}/MovingBoundary
cp ${workDir}/MovingBoundary/SimID_599489767_0_*  ${archiveDir}/MovingBoundary
rm ${workDir}/MovingBoundary/*

#
# Test NFsim_x64
#
mkdir -p ${workDir}/NFsim
rm ${workDir}/NFsim/*
cp ${inputDir}/NFsim/SimID_599489767_0_* ${workDir}/NFsim
${solverDir}/NFsim_x64 --config ${workDir}/NFsim/SimID_599489767_0_mb.xml

mkdir -p ${archiveDir}/NFsim
cp ${workDir}/NFsim/SimID_599489767_0_*  ${archiveDir}/NFsim
rm ${workDir}/NFsim/*

