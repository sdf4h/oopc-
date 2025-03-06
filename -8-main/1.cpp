#include <iostream>
#include <memory>

class IWeapon {
public:
    virtual void use() = 0;
    virtual ~IWeapon() = default;
};

class IArmor {
public:
    virtual void wear() = 0;
    virtual ~IArmor() = default;
};

class ElfWeapon : public IWeapon {
public:
    void use() override {
        std::cout << "Elven bow is used." << std::endl;
    }
};

class OrcWeapon : public IWeapon {
public:
    void use() override {
        std::cout << "Orc axe is used." << std::endl;
    }
};

class ElfArmor : public IArmor {
public:
    void wear() override {
        std::cout << "Elven armor is worn." << std::endl;
    }
};

class OrcArmor : public IArmor {
public:
    void wear() override {
        std::cout << "Orc armor is worn." << std::endl;
    }
};

class ICharacterFactory {
public:
    virtual std::unique_ptr<IWeapon> createWeapon() = 0;
    virtual std::unique_ptr<IArmor> createArmor() = 0;
    virtual ~ICharacterFactory() = default;
};

class ElfFactory : public ICharacterFactory {
public:
    std::unique_ptr<IWeapon> createWeapon() override {
        return std::make_unique<ElfWeapon>();
    }

    std::unique_ptr<IArmor> createArmor() override {
        return std::make_unique<ElfArmor>();
    }
};

class OrcFactory : public ICharacterFactory {
public:
    std::unique_ptr<IWeapon> createWeapon() override {
        return std::make_unique<OrcWeapon>();
    }

    std::unique_ptr<IArmor> createArmor() override {
        return std::make_unique<OrcArmor>();
    }
};

int main() {
    std::unique_ptr<ICharacterFactory> elfFactory = std::make_unique<ElfFactory>();
    std::unique_ptr<IWeapon> elfWeapon = elfFactory->createWeapon();
    std::unique_ptr<IArmor> elfArmor = elfFactory->createArmor();

    elfWeapon->use();
    elfArmor->wear();

    std::unique_ptr<ICharacterFactory> orcFactory = std::make_unique<OrcFactory>();
    std::unique_ptr<IWeapon> orcWeapon = orcFactory->createWeapon();
    std::unique_ptr<IArmor> orcArmor = orcFactory->createArmor();

    orcWeapon->use();
    orcArmor->wear();

    return 0;
}