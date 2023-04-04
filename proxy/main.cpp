#include <iostream>
#include <memory>

// Subject interface
class Image {
public:
    virtual void display() = 0;
};

// Real subject
class RealImage : public Image {
private:
    std::string m_fileName;
public:
    RealImage(const std::string& fileName) : m_fileName(fileName) {
        loadFromDisk();
    }
    void display() override {
        std::cout << "Displaying " << m_fileName << std::endl;
    }
    void loadFromDisk() {
        std::cout << "Loading " << m_fileName << std::endl;
    }
};

// Proxy
class ProxyImage : public Image {
private:
    std::unique_ptr<RealImage> m_realImage;
    std::string m_fileName;
public:
    ProxyImage(const std::string& fileName) : m_fileName(fileName) {}
    void display() override {
        if (!m_realImage) {
            m_realImage = std::make_unique<RealImage>(m_fileName);
        }
        m_realImage->display();
    }
};

// Client code
int main() {
    std::unique_ptr<Image> image = std::make_unique<ProxyImage>("test_image.jpg");
    image->display();
    std::cout << std::endl;
    image->display();
    return 0;
}
