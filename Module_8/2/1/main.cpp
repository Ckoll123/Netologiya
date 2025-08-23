#include <string>
#include <iostream>
#include <algorithm>
#include <memory>

class Text {
public:
    virtual void render(const std::string& data) const {
        std::cout << data;
    }
};


class DecoratedText : public Text {
public:
    explicit DecoratedText(std::unique_ptr<Text> text) : text_(std::move(text)) {}
protected:
    std::unique_ptr<Text> text_;
};

class ItalicText : public DecoratedText {
public:
    explicit ItalicText(std::unique_ptr<Text> text) : DecoratedText(std::move(text)) {}
    void render(const std::string& data)  const  {
        std::cout << "<i>";
        text_->render(data);
        std::cout << "</i>";
    }
};

class BoldText : public DecoratedText {
public:
    explicit BoldText(std::unique_ptr<Text> text) : DecoratedText(std::move(text)) {}
    void render(const std::string& data) const {
        std::cout << "<b>";
        text_->render(data);
        std::cout << "</b>";
    }
};

class Paragraph: public DecoratedText {
public:
    explicit Paragraph(std::unique_ptr<Text> text) : DecoratedText(std::move(text)) {}
    void render(const std::string& data) const {
        std::cout << "<p>";
        text_->render(data);
        std::cout << "</p>";
    }
};

class Reversed: public DecoratedText {
public:
    explicit Reversed(std::unique_ptr<Text> text) : DecoratedText(std::move(text)) {}
    void render(const std::string& data) const {
        std::string reversed_data = data;
        std::reverse(reversed_data.begin(), reversed_data.end());
        text_->render(reversed_data);
    }
};

class Link: public DecoratedText {
public:
    explicit Link(std::unique_ptr<Text> text, const std::string& url) : DecoratedText(std::move(text)), _url(url) {}
   
    void render(const std::string& data) const {
        std::cout << "<a href=" << _url << ">";
        text_->render(data);
        std::cout << "</a>";
    }
private:
    std::string _url;
};



int main() {
    auto text_block1 = std::make_unique<ItalicText>(std::make_unique<BoldText>(std::make_unique<Text>()));
    text_block1->render("Hello world");
    std::cout << std::endl;

    auto text_block2 = std::make_unique<Paragraph>(std::make_unique<Text>());
    text_block2->render("Hello world");
    std::cout << std::endl;

    auto text_block3 = std::make_unique<Reversed>(std::make_unique<Text>());
    text_block3->render("Hello world");
    std::cout << std::endl;

    auto text_block4 = std::make_unique<Link>(std::make_unique<Text>(), "netology.ru");
    text_block4->render("Hello world");
    std::cout << std::endl;
}