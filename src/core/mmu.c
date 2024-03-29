#include "mmu.h"

mmu_t* create_mmu(){
    mmu_t* mmu = malloc(sizeof(mmu_t));

    return mmu;
}

void mmu_write(mmu_t* mmu, uint16_t address, uint8_t value){
    // Internal RAM
    if(address < MMU_INTERNAL_RAM_SZ){
        mmu->internal_ram[address] = value;
        return;
    }
    address - MMU_INTERNAL_RAM_SZ;

    // Ram Mirrors
    if(address < MMU_RAM_MIRRORS_SZ){
        return;
    }
    address - MMU_RAM_MIRRORS_SZ;
    
    // PPU Registers
    if(address < MMU_PPU_REGISTERS_SZ){
        return;
    }
    address - MMU_PPU_REGISTERS_SZ;

    // PPU Mirrors
    if(address < MMU_PPU_MIRRORS_SZ){
        return;
    }
    address - MMU_PPU_MIRRORS_SZ;

    // IO and APU Registers
    if(address < MMU_IO_REGISTERS_SZ){
        return;
    }
    address - MMU_IO_REGISTERS_SZ;
    
    // Test Mode
    if(address < MMU_TEST_SZ){
        return;
    }
    address - MMU_TEST_SZ;

    // Cartridge
    if(address < MMU_CARTRIDGE_SZ){
        mmu->cartridge[address] = value;
        return;
    }
}

uint8_t mmu_read(mmu_t* mmu, uint16_t address){
    // Internal RAM
    if(address < MMU_INTERNAL_RAM_SZ){
        return mmu->internal_ram[address];
    }
    address - MMU_INTERNAL_RAM_SZ;

    // Ram Mirrors
    if(address < MMU_RAM_MIRRORS_SZ){
        return mmu->internal_ram[address];
    }
    address - MMU_RAM_MIRRORS_SZ;
    
    // PPU Registers
    if(address < MMU_PPU_REGISTERS_SZ){
        return 0;
    }
    address - MMU_PPU_REGISTERS_SZ;

    // PPU Mirrors
    if(address < MMU_PPU_MIRRORS_SZ){
        return 0;
    }
    address - MMU_PPU_MIRRORS_SZ;

    // IO and APU Registers
    if(address < MMU_IO_REGISTERS_SZ){
        return 0;
    }
    address - MMU_IO_REGISTERS_SZ;
    
    // Test Mode
    if(address < MMU_TEST_SZ){
        return 0;
    }
    address - MMU_TEST_SZ;

    // Cartridge
    if(address < MMU_CARTRIDGE_SZ){
        return mmu->cartridge[address];
    }
}
