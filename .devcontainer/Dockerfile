# Base C++ dev container
FROM mcr.microsoft.com/devcontainers/cpp:ubuntu-22.04

# Install C++ build essentials, VTK, Python and common tools
RUN apt-get update && \
    apt-get install -y \
        cmake \
        git \
        build-essential \
        libvtk7-dev \
        python3 \
        python3-pip \
        python3-venv \
        curl \
        wget \
        nano \
        && apt-get clean && rm -rf /var/lib/apt/lists/*

# Install Python dependencies required by the tests
RUN python3 -m pip install --no-cache-dir numpy seaborn matplotlib

# Set default workdir
WORKDIR /workspace
