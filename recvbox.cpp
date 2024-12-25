#include "recvbox.h"
#include "ui_recvbox.h"

// 构造函数
RecvBox::RecvBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecvBox)
{
    ui->setupUi(this); // 设置 UI 界面

    // 使 label_2 的文本可被鼠标选择
    ui->label_2->setTextInteractionFlags(Qt::TextSelectableByMouse);

    // 使 label_2 的文本自动换行
    ui->label_2->setWordWrap(true);

    // 使 label 的内容按比例缩放
    ui->label->setScaledContents(true);

    // 设置 label_2 的样式表，增加内边距
    setStyleSheet("#label_2 { padding: 12px; }");
}

// 析构函数
RecvBox::~RecvBox()
{
    delete ui; // 释放 UI 资源
}

// 设置文本颜色
void RecvBox::setTextColor(const QColor &textcolor)
{
    // 设置 label_2 的文本颜色
    setStyleSheet(QString("#label_2 {color: %1;}").arg(textcolor.name()));
}

// 设置背景颜色
void RecvBox::setBackgroundColor(const QColor &backgroundcolor)
{
    // 设置 label_2 的背景颜色
    setStyleSheet(QString("#label_2{background-color: %1;}").arg(backgroundcolor.name()));
}

// 设置圆角半径
void RecvBox::setBordetRadius(const int radius)
{
    // 设置 label_2 的圆角半径
    setStyleSheet(QString("#label_2{border-radius: %1;}").arg(QString::number(radius)));
}

// 设置样式表
void RecvBox::setStyleSheet(const QString &style)
{
    // 追加样式表，而不是覆盖
    QWidget::setStyleSheet(styleSheet() + style);
}

// 设置头像
void RecvBox::setAvatar(const QPixmap &avtar)
{
    // 创建一个椭圆形区域，用于设置 label 的遮罩
    QRegion region(ui->label->rect(), QRegion::Ellipse);
    ui->label->setMask(region); // 设置遮罩，使头像显示为圆形
    ui->label->setPixmap(avtar); // 设置头像图片
}

// 设置文本
void RecvBox::setText(const QString &text)
{
    ui->label_2->setText(text); // 设置 label_2 的文本
}

// 设置名字
void RecvBox::setName(const QString &name)
{
    ui->namelb->setText(name); // 设置 namelb 的文本
}

// 设置头衔
void RecvBox::setTitle(const QString &title)
{
    ui->titlelb->setText(title); // 设置 titlelb 的文本
}
