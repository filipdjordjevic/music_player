#include "MainWindow.hpp"

#include "player/MusicPlayer.hpp";

using namespace player;

namespace ui
{
    MainWindow::MainWindow(QWidget *parent)
        : QWidget(parent)
    {
        this->initTitlebar();

        player_ = new PlayerFrame;
        playlistView_ = new PlaylistView;

        QVBoxLayout *mainLayout = new QVBoxLayout;
        mainLayout->setContentsMargins(0, 0, 0, 0);
        mainLayout->addLayout(titleBtns_);
        mainLayout->addWidget(player_);
        mainLayout->addWidget(playlistView_);

        setLayout(mainLayout);
        this->layout()->setSizeConstraint(QLayout::SetFixedSize);

        QObject::connect(playlistView_, &PlaylistView::songDoubleClicked, [this] { player_->loadSongData(); });
        playlistView_->setContextMenuPolicy(Qt::CustomContextMenu);
        QObject::connect(playlistView_, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));
    }

    void MainWindow::paintEvent(QPaintEvent *)
    {
        QPainter painter(this);
        QColor bg = QColor("#242226");
        painter.fillRect(QRect(0, 0, this->width(), 20), bg);
    }

    void MainWindow::mousePressEvent(QMouseEvent *event)
    {
        if (event->button() == Qt::LeftButton)
        {
            dragPosition_ = event->globalPos() - frameGeometry().topLeft();
            event->accept();
        }
    }

    void MainWindow::mouseMoveEvent(QMouseEvent *event)
    {
        if (event->buttons() & Qt::LeftButton)
        {
            move(event->globalPos() - dragPosition_);
            event->accept();
        }
    }

    void MainWindow::initTitlebar()
    {
        this->setWindowFlag(Qt::FramelessWindowHint);

        titleBtns_ = new QHBoxLayout;

        QPushButton *openBtn = new QPushButton("Open");
        openBtn->setObjectName("titlebar-open");
        QObject::connect(openBtn, &QPushButton::clicked, this,
                         [this] {
                             QUrl url = QFileDialog::getOpenFileUrl(this, "Open mp3 file", QDir::homePath());
                             Song *song = new Song(url.url().toStdString());
                             MusicPlayer::instance().open(song);
                             this->player_->loadSongData();
                             playlistView_->add(song);
                         });

        QPushButton *closeBtn = new QPushButton("X");
        closeBtn->setObjectName("titlebar");
        QObject::connect(closeBtn, &QPushButton::clicked, this, [this] { this->close(); });

        QPushButton *minimizeBtn = new QPushButton("-");
        minimizeBtn->setObjectName("titlebar");
        QObject::connect(minimizeBtn, &QPushButton::clicked, this, [this] { this->setWindowState(Qt::WindowMinimized); });

        titleBtns_->addWidget(openBtn);
        titleBtns_->addStretch();
        titleBtns_->addWidget(minimizeBtn);
        titleBtns_->addWidget(closeBtn);
    }

    void MainWindow::showContextMenu(const QPoint &pos)
    {
        QPoint globalPos = playlistView_->mapToGlobal(pos);

        QMenu menu;
        menu.addAction("Remove", this, SLOT(removeItem()));

        menu.exec(globalPos);
    }

    void MainWindow::removeItem()
    {
        SongListItem *item = static_cast<SongListItem *>(playlistView_->currentItem());
        playlistView_->deleteItem(item);
    }
} // namespace ui