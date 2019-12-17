#ifndef THIRD_H
#define THIRD_H

#include <QMainWindow>

namespace Ui {
class Third;
}

struct contact{
    std::string firstname;
    std::string last_name;
    contact(){}
    contact(const std::string &last, const std:: string & first) :
    firstname(first), last_name(last){
}
};

class Third : public QMainWindow
{
    Q_OBJECT

public:
    explicit Third(QWidget *parent = nullptr);
    ~Third();

private slots:
    void on_button_back_clicked();

    void on_button_next_clicked();

    void on_button_add_clicked();

private:
    Ui::Third *ui;

    std::vector<contact> contact_list;

    void updateUI();


};

#endif // THIRD_H
