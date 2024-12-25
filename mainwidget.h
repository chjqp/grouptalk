#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QScrollBar>
#include <QListWidget>
#include <QPushButton>
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
    QScrollBar *scrollBar;

    QPushButton *toolVideoButton;
    QPushButton *toolExtraButton;
    QPushButton *toolPicButton;
    QPushButton *toolEmojiButton;
    QPushButton *toolSendButton;

    QList<UserWidget*> friendsList;

    void setupScrollBar();
    void setupButton(QPushButton *button, const QString &iconPath, const QRect &geometry);
    QString loadImageAsBase64(const QString &imagePath);
    void addFriend(const QString& name, const QString& title, const QPixmap& avatar);
    void addChatItem(const QString& message);
    void raiseButtons();
};

#endif // MAINWIDGET_H
