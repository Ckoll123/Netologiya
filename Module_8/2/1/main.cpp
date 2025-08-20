#include <string>
#include <iostream>
#include <algorithm>

class Text {
public:
    virtual void render(const std::string& data) const {
        std::cout << data;
    }
};


class DecoratedText : public Text {
public:
    explicit DecoratedText(Text* text) : text_(text) {}
    Text* text_;
};

class ItalicText : public DecoratedText {
public:
    explicit ItalicText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data)  const  {
        std::cout << "<i>";
        text_->render(data);
        std::cout << "</i>";
    }
};

class BoldText : public DecoratedText {
public:
    explicit BoldText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::cout << "<b>";
        text_->render(data);
        std::cout << "</b>";
    }
};

class Paragraph: public DecoratedText {
public:
    explicit Paragraph(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::cout << "<p>";
        text_->render(data);
        std::cout << "</p>";
    }
};

class Reversed: public DecoratedText {
public:
    explicit Reversed(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::string reversed_data = data;
        std::reverse(reversed_data.begin(), reversed_data.end());
        text_->render(reversed_data);
    }
};

class Link: public DecoratedText {
public:
    explicit Link(Text* text, const std::string& url) : DecoratedText(text), url_(url) {}
    // explicit Link(Text* text) : DecoratedText(text) {}
   
    void render(const std::string& data) const {
        std::cout << "<a href=" << url_ << ">";
        text_->render(data);
        std::cout << "</a>";
    }

    // void render(const std::string& url, const std::string& text) {
    //     std::cout << "<a href=\"" << url << "\">" << text << "</a>";
    // }
private:
    std::string url_;
};



int main() {
    auto text_block1 = new ItalicText(new BoldText(new Text()));
    text_block1->render("Hello world");
    std::cout << std::endl;

    auto text_block2 = new Paragraph(new Text());
    text_block2->render("Hello world");
    std::cout << std::endl;

    auto text_block3 = new Reversed(new Text());
    text_block3->render("Hello world");
    std::cout << std::endl;

    // auto text_block4 = new Link(new Text());
    // text_block4->render("netology.ru", "Hello world");
    auto text_block4 = new Link(new Text(), "link");
    text_block4->render("Hello world");
    std::cout << std::endl;
}