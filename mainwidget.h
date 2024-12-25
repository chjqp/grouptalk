#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QScrollBar>
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QList>
#include "userwidget.h"
namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    Ui::MainWidget *ui;
    QListWidget *friendsListWidget;
    QListWidget *chatListWidget;

    QPushButton *toolVideoButton;
    QPushButton *toolExtraButton;
    QPushButton *toolPicButton;
    QPushButton *toolEmojiButton;
    QPushButton *toolSendButton;
    QLineEdit *inputField; // 新增输入框

    QList<UserWidget*> friendsList;

    void setupButton(QPushButton *button, const QString &iconPath, const QRect &geometry);
    void setupInputField(QLineEdit *inputField, const QString &iconPath, const QRect &geometry); // 新增方法声明
    QString loadImageAsBase64(const QString &imagePath);
    void addFriend(const QString& name, const QString& title, const QPixmap& avatar);
    void addChatItem(const QString& message);
    void raisetools(); // 新增方法声明
    void sendMessage();
};

#endif // MAINWIDGET_H
