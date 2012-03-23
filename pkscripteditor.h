#ifndef PKSCRIPTEDITOR_H
#define PKSCRIPTEDITOR_H

#include <QtGui>
#include <QWidget>
#include <QTextEdit>

class Gutter : public QWidget
{
    Q_OBJECT

public:
    Gutter(QWidget *parent = 0);
    void setTextEdit(QTextEdit* textEdit);
    void paintEvent(QPaintEvent *paintEvent);

private:
    int _currentLine;
    QTextEdit* _textEdit;
};

class PKScriptEditor : public QWidget
{
    Q_OBJECT
public:
    explicit PKScriptEditor(QWidget *parent = 0);
    QTextEdit* editor() { return _textEdit; }

signals:
    
public slots:
    
private:
    QTextEdit* _textEdit;
    QHBoxLayout* _hboxLayout;
    Gutter* _gutter;

};

#endif // PKSCRIPTEDITOR_H
