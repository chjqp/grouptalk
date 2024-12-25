#ifndef USERWIDGET_H
#define USERWIDGET_H

#include <QWidget>
#include <QPixmap>

namespace Ui {
class UserWidget;
}

class UserWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UserWidget(QWidget *parent = nullptr);
    ~UserWidget();

    // 设置用户名字
    void setUserName(const QString& name);
    // 获取用户名字
    QString getUserName() const;

    // 设置用户头衔
    void setUserTitle(const QString& title);
    // 获取用户头衔
    QString getUserTitle() const;

    // 设置用户头像
    void setUserAvatar(const QPixmap& avatar);
    // 获取用户头像
    QPixmap getUserAvatar() const;

private:
    Ui::UserWidget *ui;
};

#endif // USERWIDGET_H
