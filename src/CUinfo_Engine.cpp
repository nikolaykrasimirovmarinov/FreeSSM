/*
 * CUinfo_Engine.cpp - Widget for displaying Engine Control Unit information
 *
 * Copyright (C) 2008-2012 Comer352L
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "CUinfo_Engine.h"


CUinfo_Engine::CUinfo_Engine(QWidget * parent) : QWidget(parent)
{
	setupUi(this);
	setupUiFonts();
}


CUinfo_Engine::~CUinfo_Engine()
{
}


void CUinfo_Engine::setEngineTypeText(QString Type)
{
	systemType_label->setText(Type);
}


void CUinfo_Engine::setRomIDText(QString RomID)
{
	romID_label->setText(RomID);
}


void CUinfo_Engine::setVINinfo(bool VINsupported, QString VIN)
{
	QColor VINcolor;
	QPalette VINlabel_palette;
	if (VINsupported)
	{
		if (VIN.size() == 0)
		{
			VIN_label->setText(tr("not programmed yet"));
			VINcolor.setRgb( 255, 170, 0, 255);	// r,g,b,alpha: orange
		}
		else
		{
			VIN_label->setText(VIN);
			VINcolor.setRgb( 0, 170, 0, 255);	// r,g,b,alpha: green
		}
	}
	else
	{
		VIN_label->setText(tr("not supported by ECU"));
		VINcolor.setRgb( 255, 0, 0, 255);	// r,g,b,alpha: red
	}
	VINlabel_palette = VIN_label->palette();
	VINlabel_palette.setColor(QPalette::Active, QPalette::WindowText, VINcolor);
	VINlabel_palette.setColor(QPalette::Inactive, QPalette::WindowText, VINcolor);
	VIN_label->setPalette(VINlabel_palette);
}


void CUinfo_Engine::setNrOfSupportedMBsSWs(unsigned int MBs, unsigned int SWs)
{
	nrofdatambs_label->setText( QString::number(MBs, 10) );
	nrofswitches_label->setText( QString::number(SWs, 10) );
}


void CUinfo_Engine::setOBD2Supported(bool sup)
{
	if (sup)
		obd2system_label->setPixmap(QPixmap(QString::fromUtf8(":/icons/chrystal/22x22/ok.png")));
	else
		obd2system_label->setPixmap(QPixmap(QString::fromUtf8(":/icons/chrystal/22x22/editdelete.png")));
}


void CUinfo_Engine::setIntegratedCCSupported(bool sup)
{
	if (sup)
		ccintegrated_label->setPixmap(QPixmap(QString::fromUtf8(":/icons/chrystal/22x22/ok.png")));
	else
		ccintegrated_label->setPixmap(QPixmap(QString::fromUtf8(":/icons/chrystal/22x22/editdelete.png")));
}


void CUinfo_Engine::setImmobilizerSupported(bool sup)
{
	if (sup)
		immobilizer_label->setPixmap(QPixmap(QString::fromUtf8(":/icons/chrystal/22x22/ok.png")));
	else
		immobilizer_label->setPixmap(QPixmap(QString::fromUtf8(":/icons/chrystal/22x22/editdelete.png")));
}


void CUinfo_Engine::setupUiFonts()
{
	// SET FONT FAMILY AND FONT SIZE
	// OVERWRITES SETTINGS OF ui_CUinfo_Engine.h (made with QDesigner)
	QFont appfont = QApplication::font();
	QFont font = this->font();
	font.setFamily(appfont.family());
	font.setPixelSize(12);	// 9pts
	this->setFont(font);
	font = systemTypeTitle_label->font();
	font.setFamily(appfont.family());
	font.setPixelSize(12);	// 9pts
	systemTypeTitle_label->setFont(font);
	font = systemType_label->font();
	font.setFamily(appfont.family());
	font.setPixelSize(12);	// 9pts
	systemType_label->setFont(font);
	font = romIDtitle_label->font();
	font.setFamily(appfont.family());
	font.setPixelSize(12);	// 9pts
	romIDtitle_label->setFont(font);
	font = romID_label->font();
	font.setFamily(appfont.family());
	font.setPixelSize(12);	// 9pts
	romID_label->setFont(font);
	font = VINtitle_label->font();
	font.setFamily(appfont.family());
	font.setPixelSize(12);	// 9pts
	VINtitle_label->setFont(font);
	font = VIN_label->font();
	font.setFamily(appfont.family());
	font.setPixelSize(12);	// 9pts
	VIN_label->setFont(font);
	font = nrofmbsswstitle_label->font();
	font.setFamily(appfont.family());
	font.setPixelSize(12);	// 9pts
	nrofmbsswstitle_label->setFont(font);
	font = nrofdatambstitle_label->font();
	font.setFamily(appfont.family());
	font.setPixelSize(12);	// 9pts
	nrofdatambstitle_label->setFont(font);
	font = nrofdatambs_label->font();
	font.setFamily(appfont.family());
	font.setPixelSize(12);	// 9pts
	nrofdatambs_label->setFont(font);
	font = nrofswitchestitle_label->font();
	font.setFamily(appfont.family());
	font.setPixelSize(12);	// 9pts
	nrofswitchestitle_label->setFont(font);
	font = nrofswitches_label->font();
	font.setFamily(appfont.family());
	font.setPixelSize(12);	// 9pts
	nrofswitches_label->setFont(font);
	font = obd2systemTitle_label->font();
	font.setFamily(appfont.family());
	font.setPixelSize(12);	// 9pts
	obd2systemTitle_label->setFont(font);
	font = integCCtitle_label->font();
	font.setFamily(appfont.family());
	font.setPixelSize(12);	// 9pts
	integCCtitle_label->setFont(font);
	font = immosupportedtitle_label->font();
	font.setFamily(appfont.family());
	font.setPixelSize(12);	// 9pts
	immosupportedtitle_label->setFont(font);
}

