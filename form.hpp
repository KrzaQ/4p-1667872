#ifndef FORM_HPP
#define FORM_HPP

#include <QWidget>
#include <QCloseEvent>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

protected:
    void closeEvent(QCloseEvent* event) override;

private:
    Ui::Form *ui;
};

#endif // FORM_HPP
