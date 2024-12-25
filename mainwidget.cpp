#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QPixmap>
#include <QScrollBar>
#include <QFrame>
#include <QBuffer>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>

// 构造函数
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    // 创建按钮并输出相关属性进行调试
    toolVideoButton = new QPushButton(this);
    setupButton(toolVideoButton, ":/img/toolvideo.png", QRect(1310, 62, 32, 32));

    toolExtraButton = new QPushButton(this);
    setupButton(toolExtraButton, ":/img/toolextra.png", QRect(324, 1030, 24, 24));

    toolPicButton = new QPushButton(this);
    setupButton(toolPicButton, ":/img/toolpic.png", QRect(361, 1030, 24, 24));

    toolEmojiButton = new QPushButton(this);
    setupButton(toolEmojiButton, ":/img/toolemojy.png", QRect(396, 1030, 24, 24));

    toolSendButton = new QPushButton(this);
    setupButton(toolSendButton, ":/img/toolsend.png", QRect(1113, 1030, 24, 24));

    // 初始化好友列表布局
    friendsListWidget = new QListWidget(this);
    friendsListWidget->setGeometry(0, 37, 306, 1043);
    friendsListWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    friendsListWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    friendsListWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);


    // 添加一些示例好友
    QPixmap avatar1(":/img/head1.png");
    addFriend("Alice", "Friend", avatar1);
    QPixmap avatar2(":/img/head1.png");
    for (int i = 0; i < 25; ++i) {
        addFriend("Bob", "Colleague", avatar2);
    }
    // 初始化聊天记录列表布局
    chatListWidget = new QListWidget(this);
    chatListWidget->setGeometry(306, 37, 843, 1043);
    chatListWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    chatListWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    chatListWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    // 添加一些示例聊天记录
    addChatItem("Hello, how are you?");
    addChatItem("I'm good, thank you!");
    addChatItem("What about you?");
    addChatItem("I'm doing well, thanks for asking!");

    this->show();
}

// 析构函数
MainWidget::~MainWidget()
{
    delete ui;
    // 释放按钮内存
    delete toolVideoButton;
    delete toolExtraButton;
    delete toolPicButton;
    delete toolEmojiButton;
    delete toolSendButton;
    // 释放好友列表相关内存
    qDeleteAll(friendsList);
    delete friendsListWidget;
    delete chatListWidget;
}


// 添加好友到列表的函数
void MainWidget::addFriend(const QString& name, const QString& title, const QPixmap& avatar)
{
    UserWidget *userWidget = new UserWidget();
    userWidget->setUserName(name);
    userWidget->setUserTitle(title);
    userWidget->setUserAvatar(avatar);
    userWidget->setFixedSize(306, 84);

    QListWidgetItem *item = new QListWidgetItem(friendsListWidget);
    item->setSizeHint(QSize(306, 84));
    friendsListWidget->addItem(item);
    friendsListWidget->setItemWidget(item, userWidget);

    friendsList.append(userWidget);
}

// 添加聊天记录到列表的函数
void MainWidget::addChatItem(const QString& message)
{
    QListWidgetItem *item = new QListWidgetItem(chatListWidget);
    item->setText(message);
    chatListWidget->addItem(item);
}
// 封装的设置按钮图标的方法
void MainWidget::setupButton(QPushButton *button, const QString &iconPath, const QRect &geometry)
{
    button->setGeometry(geometry);
    QPixmap pixmap(iconPath);
    if (pixmap.isNull()) {
        qDebug() << "Could not create pixmap from" << iconPath;
        return;
    }
    button->setIcon(QIcon(pixmap));
    button->setIconSize(pixmap.size());
    button->setVisible(true);
    button->setEnabled(true);
    qDebug() << button->objectName() << "geometry: " << button->geometry();
    qDebug() << button->objectName() << "visible: " << button->isVisible();
    qDebug() << button->objectName() << "enabled: " << button->isEnabled();
    qDebug() << button->objectName() << "icon size: " << button->iconSize();
}

// 封装的加载图像并转换为 base64 编码字符串的方法
QString MainWidget::loadImageAsBase64(const QString &imagePath)
{
    QPixmap pixmap(imagePath);
    QImage image = pixmap.toImage();

    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    image.save(&buffer, "PNG");
    return QString::fromLatin1(byteArray.toBase64().data());
}
// 重写 resizeEvent 函数以确保滚动区域大小随窗口调整
void MainWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    friendsListWidget->setGeometry(0, 37, 306, height() - 37);
    chatListWidget->setGeometry(306, 37, 843, height() - 37);
}
