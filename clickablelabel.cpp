    #include "clickablelabel.h"

clickablelabel::clickablelabel(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent) {

}

clickablelabel::~clickablelabel() {}

void clickablelabel::mousePressEvent(QMouseEvent* event) {
    emit clicked();
}
