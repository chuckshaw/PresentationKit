#include "pkscripteditor.h"

#include <QtGui>

Gutter::Gutter(QWidget *parent) :
    QWidget(parent)
{
    _textEdit = NULL;
    _currentLine = 0;
    setFixedWidth(fontMetrics().width(QString("0000")));
}

void Gutter::setTextEdit(QTextEdit *textEdit)
{
    _textEdit = textEdit;
    connect( _textEdit->document()->documentLayout(), SIGNAL( update(const QRectF &) ), this, SLOT( update() ) );
    connect( _textEdit->verticalScrollBar(), SIGNAL(valueChanged(int) ), this, SLOT( update() ) );
}

void Gutter::paintEvent(QPaintEvent *paintEvent)
{
    int lineCount = 0;
    int yValue = _textEdit->verticalScrollBar()->value();
    int height = yValue + _textEdit->viewport()->height();
    const QFontMetrics fm = fontMetrics();
    const int ascent = fm.ascent() + 1;

    QPainter p(this);
    p.setPen(QPen(Qt::gray));

    QAbstractTextDocumentLayout *layout = _textEdit->document()->documentLayout();
    QTextDocument* doc = _textEdit->document();


    for (QTextBlock it = doc->begin(); it != doc->end(); it = it.next())
    {
        lineCount++;
        QRectF boundingRect = layout->blockBoundingRect(it);

        QPointF pos = boundingRect.topLeft();
        if(pos.y() + boundingRect.height() < yValue)
        {
            continue;
        }
        if(pos.y() > height)
        {
            break;
        }

        QString lineNumber = QString::number(lineCount);
        p.drawText( width() - fm.width(lineNumber), qRound( pos.y() ) - yValue + ascent, lineNumber );
    }
}

PKScriptEditor::PKScriptEditor(QWidget *parent) :
    QWidget(parent)
{
    _textEdit = new QTextEdit(this);
    _textEdit->setLineWrapMode(QTextEdit::NoWrap);

    _hboxLayout = new QHBoxLayout(this);
    _hboxLayout->setContentsMargins(0,0,0,0);
    this->setLayout(_hboxLayout);

    _gutter = new Gutter(this);
    _gutter->setTextEdit(_textEdit);

    _hboxLayout->addWidget(_gutter);
    _hboxLayout->addWidget(_textEdit);
}
