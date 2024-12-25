#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "recvbox.h"
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
    setupButton(toolExtraButton, ":/img/toolextra.png", QRect(324, height() - 50, 24, 24));

    toolPicButton = new QPushButton(this);
    setupButton(toolPicButton, ":/img/toolpic.png", QRect(361, height() - 50, 24, 24));

    toolEmojiButton = new QPushButton(this);
    setupButton(toolEmojiButton, ":/img/toolemojy.png", QRect(396, height() - 50, 24, 24));

    toolSendButton = new QPushButton(this);
    setupButton(toolSendButton, ":/img/toolsend.png", QRect(1113, height() - 50, 24, 24));

    // 创建输入框并设置背景图片
    inputField = new QLineEdit(this);
    setupInputField(inputField, ":/img/toolinput.png", QRect(439, height() - 50, 664, 36));

    // 初始化好友列表布局
    friendsListWidget = new QListWidget(this);
    friendsListWidget->setGeometry(0, 37, 306, height() - 37);
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
    chatListWidget->setGeometry(316, 123, 843, 963);
    chatListWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    chatListWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    chatListWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    // 连接发送按钮的点击信号到发送消息的槽函数
    connect(toolSendButton, &QPushButton::clicked, this, &MainWidget::sendMessage);

    // 将按钮和输入框置于最上层
    raisetools();

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
    delete inputField; // 释放输入框内存
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
    button->setStyleSheet("border: none;"); // 去掉按钮边框
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

// 封装的设置输入框背景图片的方法
void MainWidget::setupInputField(QLineEdit *inputField, const QString &iconPath, const QRect &geometry)
{
    inputField->setGeometry(geometry);
    inputField->setStyleSheet(QString("QLineEdit { border: none; border-image: url(%1) 0 0 0 0 stretch stretch; }").arg(iconPath)); // 去掉输入框边框
    inputField->setVisible(true);
    inputField->setEnabled(true);
    qDebug() << inputField->objectName() << "geometry: " << inputField->geometry();
    qDebug() << inputField->objectName() << "visible: " << inputField->isVisible();
    qDebug() << inputField->objectName() << "enabled: " << inputField->isEnabled();
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
    chatListWidget->setGeometry(316, 123, 843, 963);
    toolExtraButton->setGeometry(324, height() - 50, 24, 24);
    toolPicButton->setGeometry(361, height() - 50, 24, 24);
    toolEmojiButton->setGeometry(396, height() - 50, 24, 24);
    toolSendButton->setGeometry(1113, height() - 50, 24, 24);
    inputField->setGeometry(439, height() - 50, 664, 36);

    // 确保按钮和输入框在窗口调整时保持在最上层
    raisetools();
}

// 将所有按钮置于最上层
void MainWidget::raisetools()
{
    toolVideoButton->raise();
    toolExtraButton->raise();
    toolPicButton->raise();
    toolEmojiButton->raise();
    toolSendButton->raise();
    inputField->raise();
}

// 发送消息的槽函数
void MainWidget::sendMessage()
{
    QString text = inputField->text(); // 获取输入框中的文本

    if (text.isEmpty()) {
        return; // 如果文本为空，则不发送消息
    }

    RecvBox* recvbox = new RecvBox(chatListWidget); // 创建新的 RecvBox

    // 设置 RecvBox 的固定大小
    recvbox->setFixedSize(400, 100); // 你可以根据需要调整大小

    QListWidgetItem *item = new QListWidgetItem(chatListWidget);
    item->setSizeHint(recvbox->size()); // 设置 QListWidgetItem 的大小提示为 RecvBox 的大小
    chatListWidget->addItem(item);
    chatListWidget->setItemWidget(item, recvbox);

    QPixmap p(":/img/head1.png"); // 设置头像
    recvbox->setAvatar(p);
    recvbox->setBackgroundColor(QColor("#666666"));
    recvbox->setBordetRadius(10);
    recvbox->setTextColor(Qt::black);

    recvbox->setText(text); // 设置消息文本

    inputField->clear(); // 清空输入框

    // 将滚动条值设置为最大值，以确保内容滚动到最底部
    chatListWidget->scrollToBottom();
}
