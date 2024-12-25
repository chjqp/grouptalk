#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    // 创建滚动区域
    scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);

    // 创建垂直滚动槽
    scrollBar = new QScrollBar(Qt::Vertical, this);
    scrollArea->setVerticalScrollBar(scrollBar);

    // 设置滚动条样式
    setupScrollBar();

    // 创建一个内容窗口部件并添加到滚动区域
    QWidget *contentWidget = new QWidget();
    QVBoxLayout *contentLayout = new QVBoxLayout(contentWidget);
    contentWidget->setLayout(contentLayout);

    // 添加一些示例内容
    for (int i = 0; i < 50; ++i) {
        QLabel *label = new QLabel(QString("Item %1").arg(i + 1), contentWidget);
        contentLayout->addWidget(label);
    }

    scrollArea->setWidget(contentWidget);

    // 创建布局并添加滚动区域
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(scrollArea);
    setLayout(mainLayout);
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::setupScrollBar()
{
    QString scrollBarStyle = R"(
        QScrollBar:vertical {
            border: none;
            background: #f0f0f0;
            width: 12px;
            margin: 0px 0px 0px 0px;
        }
        QScrollBar::handle:vertical {
            background: #c0c0c0;
            min-height: 20px;
            border-radius: 6px;
        }
        QScrollBar::handle:vertical:hover {
            background: #a0a0a0;
        }
        QScrollBar::add-line:vertical {
            border: none;
            background: none;
        }
        QScrollBar::sub-line:vertical {
            border: none;
            background: none;
        }
        QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {
            background: none;
        }
    )";
    scrollBar->setStyleSheet(scrollBarStyle);
}
