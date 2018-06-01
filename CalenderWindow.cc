#include "CalenderWindow.h"
#include <iostream>
#include <cstdio>

CalenderWindow::CalenderWindow()
:
  m_Frame_NotAccelerated("Not accelerated"),
  m_VBox_Main(Gtk::ORIENTATION_VERTICAL, 5),
  m_VBox(Gtk::ORIENTATION_VERTICAL),
  m_VBox_Day(Gtk::ORIENTATION_VERTICAL),
  m_VBox_Month(Gtk::ORIENTATION_VERTICAL),
  m_VBox_Year(Gtk::ORIENTATION_VERTICAL),
  m_Label_Day("Day: ", Gtk::ALIGN_START),
  m_Label_Month("Month: ", Gtk::ALIGN_START),
  m_Label_Year("Year: ", Gtk::ALIGN_START),
  m_adjustment_day( Gtk::Adjustment::create(1.0, 1.0, 31.0, 1.0, 5.0, 0.0) ),
  m_adjustment_month( Gtk::Adjustment::create(1.0, 1.0, 12.0, 1.0, 5.0, 0.0) ),
  m_adjustment_year( Gtk::Adjustment::create(2012.0, 1.0, 2200.0, 1.0, 100.0, 0.0) ),
  m_SpinButton_Day(m_adjustment_day),
  m_SpinButton_Month(m_adjustment_month),
  m_SpinButton_Year(m_adjustment_year)
  //m_Button_Close("Close")
{
  set_title("SpinButton");

  m_VBox_Main.set_border_width(10);
  add(m_VBox_Main);

  m_VBox_Main.pack_start(m_Frame_NotAccelerated);

  m_VBox.set_border_width(5);
  m_Frame_NotAccelerated.add(m_VBox);

  /* Day, month, year spinners */

  m_VBox.pack_start(m_HBox_NotAccelerated, Gtk::PACK_EXPAND_WIDGET, 5);

  m_VBox_Day.pack_start(m_Label_Day);

  m_SpinButton_Day.set_wrap();

  m_VBox_Day.pack_start(m_SpinButton_Day);

  m_HBox_NotAccelerated.pack_start(m_VBox_Day, Gtk::PACK_EXPAND_WIDGET, 5);

  m_VBox_Month.pack_start(m_Label_Month);

  m_SpinButton_Month.set_wrap();
  m_VBox_Month.pack_start(m_SpinButton_Month);

  m_HBox_NotAccelerated.pack_start(m_VBox_Month, Gtk::PACK_EXPAND_WIDGET, 5);

  m_VBox_Year.pack_start(m_Label_Year);

  m_SpinButton_Year.set_wrap();
  m_SpinButton_Year.set_size_request(55, -1);
  m_VBox_Year.pack_start(m_SpinButton_Year);

  m_HBox_NotAccelerated.pack_start(m_VBox_Year, Gtk::PACK_EXPAND_WIDGET, 5);

  

  //Close button:
  m_Button_Close.signal_clicked().connect( sigc::mem_fun(*this,
              &CalenderWindow::on_button_close) );
  m_VBox_Main.pack_start(m_Button_Close, Gtk::PACK_SHRINK);

  show_all_children();
}

CalenderWindow::~CalenderWindow()
{
}


void CalenderWindow::on_button_close()
{
  hide();
}

