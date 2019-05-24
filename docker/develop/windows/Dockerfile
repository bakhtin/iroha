# escape=`
FROM mcr.microsoft.com/powershell:nanoserver-1809
WORKDIR C:\ci
ARG TRIPLET_NAME=x64-windows
SHELL ["powershell", "-ExecutionPolicy", "Bypass", "-Command", "$ErrorActionPreference = 'Stop'; $ProgressPreference = 'SilentlyContinue';"]
RUN iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))
RUN choco feature enable -n allowGlobalConfirmation ; `
  choco install cmake --version 3.14.4 ; `
  choco install protoc --version 3.5.1 ; `
  choco install visualstudio2017-workload-vctools --version 1.3.2 --params="'--wait'" ; `
  choco install git ; `
  choco install curl
RUN git clone https://github.com/Microsoft/vcpkg.git .\vcpkg ; `
  .\vcpkg\bootstrap-vcpkg.bat
RUN git -C .\vcpkg checkout b0b895bff642afc8bc33c827b0b4430c6f8353b2 ; `
  .\vcpkg\vcpkg.exe install `
    protobuf:x64-windows `
    grpc:x64-windows `
    tbb:x64-windows `
    gtest:x64-windows `
    gflags:x64-windows `
    soci[boost,postgresql]:x64-windows `
    boost-filesystem:x64-windows `
    boost-system:x64-windows `
    boost-thread:x64-windows `
    boost-variant:x64-windows `
    boost-multiprecision:x64-windows `
    boost-bimap:x64-windows `
    boost-format:x64-windows `
    boost-circular-buffer:x64-windows `
    boost-assign:x64-windows `
    boost-uuid:x64-windows `
    boost-accumulators:x64-windows `
    boost-property-tree:x64-windows `
    boost-process:x64-windows ; `
    # TODO: Export installed packages somewhere...
  # ./vcpkg/vcpkg export 
  # del /Q ./vcpkg
RUN $env:PATH += ";C:\Program Files\CMake\bin"