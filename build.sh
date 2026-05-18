#!/usr/bin/env bash

# Salir inmediatamente si algún comando falla
set -e

# Colores para la terminal
GREEN='\033[0;32m'
BLUE='\033[0;34m'
RED='\033[0;31m'
NC='\033[0m' # No Color

echo -e "${BLUE}🧹 Cleaning old compilations ...${NC}"
rm -rf build

echo -e "${BLUE}📁 Creating build directory...${NC}"
mkdir build
cd build

echo -e "${BLUE}⚙️ Setup project with CMake...${NC}"
cmake ..

echo -e "${BLUE}🏗️ Compiling project with $(nproc) cores...${NC}"
make -j$(nproc)

echo -e "${GREEN}✅ ¡Successfully project building process!${NC}"

# Preguntar si se desean ejecutar las pruebas inmediatamente
echo -e "${BLUE}🧪 ¿Do you want to run unit tests? (y/n)${NC}"
read -r respuesta

if [[ "$respuesta" =~ ^[Yy]$ ]]; then
    echo -e "${BLUE}🏃 Running ctest...${NC}"
    ctest --output-on-failure
fi
