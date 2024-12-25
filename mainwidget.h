#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QScrollBar>
#include <QScrollArea>

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private:
    Ui::MainWidget *ui;
    QScrollBar *scrollBar;
    QScrollArea *scrollArea;

    void setupScrollBar();
};

#endif // MAINWIDGET_H
