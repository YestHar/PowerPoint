#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include <memory>
#include <variant>


class ICommand {
public:
    // virtual std::unique_ptr<ICommand> create() = 0;
    virtual void exe() = 0;
};

class AddSlide : public ICommand {
private:
    /* data */
public:
    AddSlide(/* args */);
    ~AddSlide();
    void exe() override;
};

class RemoveSlide : public ICommand {
private:
    /* data */
public:
    RemoveSlide(/* args */);
    ~RemoveSlide();
    void exe() override;
};

class Exit : public ICommand {
private:
    /* data */
public:
    Exit(/* args */);
    ~Exit();
    void exe() override;
};

class Help : public ICommand {
private:
    /* data */
public:
    Help(/* args */);
    ~Help();
    void exe() override;
};

class View : public ICommand {
private:
    /* data */
public:
    View(/* args */);
    ~View();
    void exe() override;
};

class ChangeSlideBg : public ICommand {
private:
    /* data */
public:
    ChangeSlideBg(/* args */);
    ~ChangeSlideBg();
    void exe() override;
};

class SwapSlide : public ICommand {
private:
    /* data */
public:
    SwapSlide(/* args */);
    ~SwapSlide();
    void exe() override;
};



#endif // COMMAND_HPP
