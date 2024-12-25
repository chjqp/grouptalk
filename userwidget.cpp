#include "userwidget.h"
#include "ui_userwidget.h"
#include <QBuffer>
UserWidget::UserWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserWidget)
{
    ui->setupUi(this);

}

UserWidget::~UserWidget()
{
    delete ui;
}

// 设置用户名字
void UserWidget::setUserName(const QString& name)
{
    ui->namelb->setText(name);
}

// 获取用户名字
QString UserWidget::getUserName() const
{
    return ui->namelb->text();
}

// 设置用户头衔
void UserWidget::setUserTitle(const QString& title)
{
    ui->titlelb->setText(title);
}

// 获取用户头衔
QString UserWidget::getUserTitle() const
{
    return ui->titlelb->text();
}

// 设置用户头像
void UserWidget::setUserAvatar(const QPixmap& avatar)
{
    // ui->avatarlb->setPixmap(avatar);
    // 将 QPixmap 转换为 QImage
    QImage image = avatar.toImage();

    // 将 QImage 转换为 base64 编码的字符串
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    image.save(&buffer, "PNG");
    QString base64Image = QString::fromLatin1(byteArray.toBase64().data());

    // 使用样式表设置背景图像
    QString styleSheet = QString("background-image: url(data:image/png;base64,%1); background-repeat: no-repeat; background-position: center;").arg(base64Image);
    this->setStyleSheet(styleSheet);
}

// 获取用户头像
QPixmap UserWidget::getUserAvatar() const
{
    return ui->avatarlb->pixmap();
}
