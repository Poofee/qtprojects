#include "fancytabwidget.h"

#include <QPainter>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStackedLayout>
#include <QPixmapCache>
#include <QDebug>
#include <QLabel>



FancyTabBar::FancyTabBar(QWidget *parent)
    : QWidget(parent)
{
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
//    setAttribute(Qt::WA_OpaquePaintEvent, true);
//    setFocusPolicy(Qt::NoFocus);
    setMouseTracking(true);

//    setMinimumSize(300,300);
}

/** 刚开始无法接受其他事件，就是因为给这个返回值直接true了。。。 **/
//bool FancyTabBar::event(QEvent *e)
//{
//    qDebug()<<Q_FUNC_INFO;
//    return QWidget::event(e);
//}

void FancyTabBar::paintEvent(QPaintEvent *e)
{
//    qDebug()<<Q_FUNC_INFO;

    QPainter painter(this);

    for(int i = 0; i < count();++i)
        if(i != currentIndex())
            paintTab(&painter,i);

    if(currentIndex() != -1)
        paintTab(&painter, currentIndex());
}
static void drawIconWithShadow(const QIcon &icon, const QRect &rect,
                                     QPainter *p, QIcon::Mode iconMode, int dipRadius, const QColor &color, const QPoint &dipOffset)
{
    QPixmap cache;
    const int devicePixelRatio = p->device()->devicePixelRatio();
    QString pixmapName = QString::fromLatin1("icon %0 %1 %2 %3")
            .arg(icon.cacheKey()).arg(iconMode).arg(rect.height()).arg(devicePixelRatio);

    if (!QPixmapCache::find(pixmapName, cache)) {
        // High-dpi support: The in parameters (rect, radius, offset) are in
        // device-independent pixels. The call to QIcon::pixmap() below might
        // return a high-dpi pixmap, which will in that case have a devicePixelRatio
        // different than 1. The shadow drawing caluculations are done in device
        // pixels.
        QWindow *window = dynamic_cast<QWidget*>(p->device())->window()->windowHandle();
        QPixmap px = icon.pixmap(window, rect.size(), iconMode);
        int radius = dipRadius * devicePixelRatio;
        QPoint offset = dipOffset * devicePixelRatio;
        cache = QPixmap(px.size() + QSize(radius * 2, radius * 2));
        cache.fill(Qt::transparent);

        QPainter cachePainter(&cache);
//        if (iconMode == QIcon::Disabled) {
//            const bool hasDisabledState =
//                    icon.availableSizes().count() == icon.availableSizes(QIcon::Disabled).count();
////            if (!hasDisabledState)
////                px = disabledSideBarIcon(icon.pixmap(window, rect.size()));
//        } else if (creatorTheme()->flag(Theme::ToolBarIconShadow)) {
//            // Draw shadow
//            QImage tmp(px.size() + QSize(radius * 2, radius * 2 + 1), QImage::Format_ARGB32_Premultiplied);
//            tmp.fill(Qt::transparent);

//            QPainter tmpPainter(&tmp);
//            tmpPainter.setCompositionMode(QPainter::CompositionMode_Source);
//            tmpPainter.drawPixmap(QRect(radius, radius, px.width(), px.height()), px);
//            tmpPainter.end();

//            // blur the alpha channel
//            QImage blurred(tmp.size(), QImage::Format_ARGB32_Premultiplied);
//            blurred.fill(Qt::transparent);
//            QPainter blurPainter(&blurred);
//            qt_blurImage(&blurPainter, tmp, radius, false, true);
//            blurPainter.end();

//            tmp = blurred;

//            // blacken the image...
//            tmpPainter.begin(&tmp);
//            tmpPainter.setCompositionMode(QPainter::CompositionMode_SourceIn);
//            tmpPainter.fillRect(tmp.rect(), color);
//            tmpPainter.end();

//            tmpPainter.begin(&tmp);
//            tmpPainter.setCompositionMode(QPainter::CompositionMode_SourceIn);
//            tmpPainter.fillRect(tmp.rect(), color);
//            tmpPainter.end();

//            // draw the blurred drop shadow...
//            cachePainter.drawImage(QRect(0, 0, cache.rect().width(), cache.rect().height()), tmp);
//        }

        // Draw the actual pixmap...
        cachePainter.drawPixmap(QRect(QPoint(radius, radius) + offset, QSize(px.width(), px.height())), px);
        cachePainter.end();
        cache.setDevicePixelRatio(devicePixelRatio);
        QPixmapCache::insert(pixmapName, cache);
    }

    QRect targetRect = cache.rect();
    targetRect.setSize(targetRect.size() / cache.devicePixelRatio());
    targetRect.moveCenter(rect.center() - dipOffset);
    p->drawPixmap(targetRect, cache);
}
static void paintSelectedTabBackground(QPainter *painter, const QRect &spanRect)
{
    const int verticalOverlap = 2; // Grows up and down for the overlaps
    const int dpr = painter->device()->devicePixelRatio();
    const QString cacheKey = QLatin1String(Q_FUNC_INFO) + QString::number(spanRect.width())
                             + QLatin1Char('x') + QString::number(spanRect.height())
                             + QLatin1Char('@') + QString::number(dpr);
    QPixmap selection;
    if (!QPixmapCache::find(cacheKey, &selection)) {
        selection = QPixmap(QSize(spanRect.width(), spanRect.height() + 2 * verticalOverlap) * dpr);
        selection.fill(Qt::transparent);
        selection.setDevicePixelRatio(dpr);
        QPainter p(&selection);
        p.translate(QPoint(0, verticalOverlap));

        const QRect rect(QPoint(), spanRect.size());
        const QRectF borderRect = QRectF(rect).adjusted(0.5, 0.5, -0.5, -0.5);

        //background
        p.save();
        QLinearGradient grad(rect.topLeft(), rect.topRight());
        grad.setColorAt(0, QColor(255, 255, 255, 140));
        grad.setColorAt(1, QColor(255, 255, 255, 210));
        p.fillRect(rect, grad);
        p.restore();

        //shadows
        p.setPen(QColor(0, 0, 0, 110));
        p.drawLine(borderRect.topLeft() + QPointF(1, -1), borderRect.topRight() - QPointF(0, 1));
        p.drawLine(borderRect.bottomLeft(), borderRect.bottomRight());
        p.setPen(QColor(0, 0, 0, 40));
        p.drawLine(borderRect.topLeft(), borderRect.bottomLeft());

        //highlights
        p.setPen(QColor(255, 255, 255, 50));
        p.drawLine(borderRect.topLeft() + QPointF(0, -2), borderRect.topRight() - QPointF(0, 2));
        p.drawLine(borderRect.bottomLeft() + QPointF(0, 1),
                   borderRect.bottomRight() + QPointF(0, 1));
        p.setPen(QColor(255, 255, 255, 40));
        p.drawLine(borderRect.topLeft() + QPointF(0, 0), borderRect.topRight());
        p.drawLine(borderRect.topRight() + QPointF(0, 1), borderRect.bottomRight() - QPointF(0, 1));
        p.drawLine(borderRect.bottomLeft() + QPointF(0, -1),
                   borderRect.bottomRight() - QPointF(0, 1));
        p.end();

        QPixmapCache::insert(cacheKey, selection);
    }
    painter->drawPixmap(spanRect.topLeft() + QPoint(0, -verticalOverlap), selection);
}

static void paintIcon(QPainter *painter, const QRect &rect,
                      const QIcon &icon,
                      bool enabled, bool selected)
{
    const QIcon::Mode iconMode = enabled ? (selected ? QIcon::Active : QIcon::Normal)
                                         : QIcon::Disabled;
    QRect iconRect(0, 0, 64, 64);
    iconRect.moveCenter(rect.center());
    iconRect = iconRect.intersected(rect);
//    if (!enabled && !creatorTheme()->flag(Theme::FlatToolBars))
    painter->setOpacity(0.7);
    drawIconWithShadow(icon, iconRect, painter, iconMode,3, QColor(0, 0, 0, 130),QPoint(1, -2));
}

//static void paintIconAndText(QPainter *painter, const QRect &rect,
//                             const QIcon &icon, const QString &text,
//                             bool enabled, bool selected)
//{
//    QFont boldFont(painter->font());
//    boldFont.setPointSizeF(StyleHelper::sidebarFontSize());
//    boldFont.setBold(true);
//    painter->setFont(boldFont);

//    const bool drawIcon = rect.height() > 36;
//    if (drawIcon) {
//        const int textHeight =
//                painter->fontMetrics().boundingRect(rect, Qt::TextWordWrap, text).height();
//        const QRect tabIconRect(rect.adjusted(0, 4, 0, -textHeight));
//        const QIcon::Mode iconMode = enabled ? (selected ? QIcon::Active : QIcon::Normal)
//                                             : QIcon::Disabled;
//        QRect iconRect(0, 0, Core::Constants::MODEBAR_ICON_SIZE, Core::Constants::MODEBAR_ICON_SIZE);
//        iconRect.moveCenter(tabIconRect.center());
//        iconRect = iconRect.intersected(tabIconRect);
//        if (!enabled && !creatorTheme()->flag(Theme::FlatToolBars))
//            painter->setOpacity(0.7);
//        StyleHelper::drawIconWithShadow(icon, iconRect, painter, iconMode);
//    }

//    painter->setOpacity(1.0); //FIXME: was 0.7 before?
//    if (enabled) {
//        painter->setPen(
//            selected ? creatorTheme()->color(Theme::FancyTabWidgetEnabledSelectedTextColor)
//                     : creatorTheme()->color(Theme::FancyTabWidgetEnabledUnselectedTextColor));
//    } else {
//        painter->setPen(
//            selected ? creatorTheme()->color(Theme::FancyTabWidgetDisabledSelectedTextColor)
//                     : creatorTheme()->color(Theme::FancyTabWidgetDisabledUnselectedTextColor));
//    }

//    painter->translate(0, -1);
//    QRect tabTextRect(rect);
//    tabTextRect.translate(0, drawIcon ? -2 : 1);
//    const int textFlags = Qt::AlignCenter | (drawIcon ? Qt::AlignBottom : Qt::AlignVCenter)
//                          | Qt::TextWordWrap;
//    painter->drawText(tabTextRect, textFlags, text);
//}

void FancyTabBar::paintTab(QPainter *painter, int index) const
{
//    qDebug()<<Q_FUNC_INFO<<":"<<index;
    if(!validIndex(index))
        return;

    painter->save();

    const FancyTab *tab = m_tabs.at(index);
    const QRect rect = tabRect(index);
    const bool selected = (index == currentIndex());
    const bool enabled = isTabEnabled(index);
    /** 绘制选中的背景 **/
    if(selected){
        painter->fillRect(rect, QBrush(QColor(183, 221, 250,200)));
        painter->setPen(QColor(18, 145, 243));
        painter->drawRect(rect);
    }

    if(m_iconsOnly){
        paintIcon(painter, rect, tab->icon, enabled, selected);
    }else{
//        paintIconAndText(painter, rect, tab->icon, tab->text, enabled, selected);
    }

    painter->restore();
}

void FancyTabBar::mousePressEvent(QMouseEvent *event)
{
//    qDebug()<<Q_FUNC_INFO;
    event->accept();
    for (int index = 0; index < m_tabs.count(); ++index) {
        const QRect rect = tabRect(index);
        if (rect.contains(event->pos())) {
            if (isTabEnabled(index)) {
                m_currentIndex = index;
                update();
                emit currentChanged(m_currentIndex);
            }
            break;
        }
    }
}

void FancyTabBar::mouseMoveEvent(QMouseEvent *e)
{
//    qDebug()<<Q_FUNC_INFO;
}

void FancyTabBar::enterEvent(QEvent *e)
{
//    qDebug()<<Q_FUNC_INFO;
}

void FancyTabBar::leaveEvent(QEvent *e)
{
//    qDebug()<<Q_FUNC_INFO;
}

void FancyTabBar::setTabEnabled(int index, bool enable)
{
    if(index >=0 && index < m_tabs.size()){
        m_tabs[index]->enabled = enable;
//        update(m_tabs[index]);
    }
}

bool FancyTabBar::isTabEnabled(int index) const
{
    if(index >= 0 && index < m_tabs.size())
        return m_tabs[index]->enabled;

    return false;
}

void FancyTabBar::setIconsOnly(bool iconOnly)
{
    m_iconsOnly = iconOnly;
}

/**sizeHint在未被重载的情况下，如果该窗口部件属于某个布局管理器，
那么返回的值为QT为这个部件推荐的尺寸。如果不属于任何布局管理器的
时候返回无效的值**/
QSize FancyTabBar::sizeHint() const
{
    const QSize sh = tabSizeHint();
//    qDebug()<<Q_FUNC_INFO<<":"<<sh.width()<<","<< sh.height();
    return {sh.width() * m_tabs.count(), sh.height()};
}

QSize FancyTabBar::minimumSizeHint() const
{
    const QSize sh = tabSizeHint(true);
//    qDebug()<<Q_FUNC_INFO<<":"<<sh.width()<<","<< sh.height();
    return {sh.width() * m_tabs.count(), sh.height()};
}

QRect FancyTabBar::tabRect(int index) const
{
    QSize sh = tabSizeHint();

//    if (sh.height() * m_tabs.count() > height())
//        sh.setHeight(height() / m_tabs.count());

    return {index * sh.width(), 0, sh.width(), sh.height()};
}

QSize FancyTabBar::tabSizeHint(bool minimum) const
{
    if (m_iconsOnly) {
        return {64+8, 64+8 / (minimum ? 3 : 1)};
    }

    QFont boldFont(font());
    boldFont.setPointSizeF(20);
    boldFont.setBold(true);
    const QFontMetrics fm(boldFont);
    const int spacing = 8;
    const int width = 60 + spacing + 2;
    int maxLabelwidth = 0;
    for (auto tab : (m_tabs)) {
        const int width = fm.width(tab->text);
        if (width > maxLabelwidth)
            maxLabelwidth = width;
    }
    const int iconHeight = minimum ? 0 : 32;
    return {qMax(width, maxLabelwidth + 4), iconHeight + spacing + fm.height()};
}
//////////////////////////////////////////
//
//
//         FancyTabWidget
//
//
//////////////////////////////////////////
FancyTabWidget::FancyTabWidget(QWidget *parent)
    : QWidget(parent)
    ,background(new QWidget())
{
    QPalette pal(background->palette());

//    painter.setRenderHint(QPainter::Antialiasing, true);
    QLinearGradient linearGradient(0,0,0,64);
    linearGradient.setColorAt(0, QColor(220,220,220));
    linearGradient.setColorAt(0.25, QColor(200,200,200));
    linearGradient.setColorAt(0.5, QColor(180,180,180));
    linearGradient.setColorAt(0.75, QColor(200,200,200));
    linearGradient.setColorAt(1.0, QColor(220,220,220));
//    painter.setBrush(QBrush(linearGradient));
//    painter.drawEllipse(50, 50, 200, 150);

    pal.setBrush(QPalette::Background, QBrush(linearGradient));
    background->setAutoFillBackground(true);
    background->setPalette(pal);

    m_tabbar = new FancyTabBar(this);

    /** 顶部栏的水平布局 **/
    QHBoxLayout *tabbarLayout = new QHBoxLayout;
    tabbarLayout->setSpacing(0);
    tabbarLayout->setMargin(0);

    tabbarLayout->addStretch(1);
    tabbarLayout->addWidget(m_tabbar);
    tabbarLayout->addStretch(1);

    background->setLayout(tabbarLayout);

    m_pages = new QStackedLayout;

    QVBoxLayout *mainLayout = new QVBoxLayout;

    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);
    mainLayout->addWidget(background);
    mainLayout->addLayout(m_pages);

    this->setLayout(mainLayout);

    connect(m_tabbar, &FancyTabBar::currentChanged, this, &FancyTabWidget::showWidget);
}

void FancyTabWidget::insertTab(int index, QWidget *tab, const QIcon &icon, const QString &label)
{
    m_pages->insertWidget(index, tab);
    m_tabbar->insertTab(index, icon, label);
}

void FancyTabWidget::removeTab(int index)
{
    m_pages->removeWidget(m_pages->widget(index));
    m_tabbar->removeTab(index);
}

void FancyTabWidget::paintEvent(QPaintEvent *event)
{

}

//void FancyTabWidget::paintEvent(QPaintEvent *event)
//{

//}

int FancyTabWidget::currentIndex() const
{
    return m_tabbar->currentIndex();
}

void FancyTabWidget::setTabEnabled(int index, bool enable)
{
    m_tabbar->setTabEnabled(index, enable);
}

bool FancyTabWidget::isTabEnabled(int index) const
{
    return  m_tabbar->isTabEnabled(index);
}

void FancyTabWidget::setIconsOnly(bool iconsOnly)
{
    m_tabbar->setIconsOnly(iconsOnly);
}


void FancyTabWidget::setCurrentIndex(int index)
{
    m_tabbar->setCurrentIndex(index);
}

void FancyTabWidget::showWidget(int index)
{
    emit currentAboutToShow(index);
    m_pages->setCurrentIndex(index);
    QWidget *w = m_pages->currentWidget();
//    if (QTC_GUARD(w)) {
        if (QWidget *focusWidget = w->focusWidget())
            w = focusWidget;
        w->setFocus();
//    }
    emit currentChanged(index);
}

