#include "ecaplayer.h"
#include "ecaplayercontrols.h"

#include <QMediaService>
#include <QVideoProbe>
#include <QAudioProbe>
#include <QMediaMetaData>
#include <QtWidgets>
#include <QVideoWidget>

EcaPlayer::EcaPlayer(QWidget *parent) : QWidget(parent)
{
	//streaming
	m_videoWidget = new QVideoWidget(this);
	m_player = new QMediaPlayer(this);

	m_player->setMedia(QUrl("rtsp://192.168.1.1:9099/stream"));
	m_player->setVideoOutput(m_videoWidget);
	m_player->setVolume(50);
	m_player->play();
	m_videoWidget->show();
	
	QBoxLayout *displayLayout = new QHBoxLayout;
	displayLayout->setContentsMargins(0, 0, 0, 0);
	displayLayout->addWidget(m_videoWidget);

	//control
	/*EcaPlayerControls *controls = new EcaPlayerControls(this);
	QBoxLayout *controlLayout = new QHBoxLayout;
	controlLayout->setContentsMargins(0, 0, 0, 0);
	controlLayout->addWidget(controls);*/
	
	
	QToolButton *qtl = new QToolButton();
	qtl->setIcon(style()->standardIcon(QStyle::SP_DialogSaveButton));
	QToolButton *qtl2 = new QToolButton();
	QToolButton *qtl3 = new QToolButton();
	QToolButton *qtl4 = new QToolButton();

	QBoxLayout *controlLayout = new QHBoxLayout;
	controlLayout->addStretch();
	controlLayout->setContentsMargins(0, 0, 0, 0);
	controlLayout->setSpacing(0);
	controlLayout->addWidget(qtl);
	controlLayout->addWidget(qtl2);
	controlLayout->addWidget(qtl3);
	controlLayout->addWidget(qtl4);
	controlLayout->addStretch();

	//main
	QBoxLayout *layout = new QVBoxLayout;
	layout->setContentsMargins(0, 0, 0, 0);
	layout->addLayout(displayLayout);
	layout->addLayout(controlLayout);
	setLayout(layout);
	
}

EcaPlayer::~EcaPlayer()
{
}
