#include "CalenderWindow.h"
#include "Calculate.h"
#include <iostream>
#include <cstdio>


using namespace std;

CalenderWindow::CalenderWindow()
:
  m_Frame_NotAccelerated(),
  m_VBox_Main(Gtk::ORIENTATION_VERTICAL, 5),
  m_VBox(Gtk::ORIENTATION_VERTICAL),
  m_VBox_Day(Gtk::ORIENTATION_VERTICAL),
  m_VBox_Month(Gtk::ORIENTATION_VERTICAL),
  m_VBox_Year(Gtk::ORIENTATION_VERTICAL),
  m_Label_Day("Day: ", Gtk::ALIGN_START),
  m_Label_Month("Month: ", Gtk::ALIGN_START),
  m_Label_Year("Year: ", Gtk::ALIGN_START),
  //m_adjustment_day( Gtk::Adjustment::create(1.0, 1.0, 31.0, 1.0, 5.0, 0.0) ),
  //m_adjustment_month( Gtk::Adjustment::create(1.0, 1.0, 12.0, 1.0, 5.0, 0.0) ),
  //m_adjustment_year( Gtk::Adjustment::create(2012.0, 1.0, 2200.0, 1.0, 100.0, 0.0) ),
  m_Button_ONE("1"),
  m_Button_TWO("2"),
  m_Button_THREE("3"),
  m_Button_FOUR("4"),
  m_Button_FIVE("5"),
  m_Button_SIX("6"),
  m_Button_SEVEN("7"),
  m_Button_EIGHT("8"),
  m_Button_NINE("9"),
  m_Button_ZERO("0"),
  m_Button_Close("Close"),
  m_Button_ADD("+"),
  m_Button_SUB("-"),
  m_Button_MUL("*"),
  m_Button_DIV("/"),
  m_Button_DEC("."),
  m_Button_EQL("="),
  m_Op(E_NONE),
  x(0),
  y(0),
  m_Grid()
{
  set_title("SpinButton");

  m_VBox_Main.set_border_width(10);
  add(m_VBox_Main);

  

  m_VBox_Main.pack_start(m_Frame_NotAccelerated);

  m_VBox.set_border_width(5);
  //m_Frame_NotAccelerated.add(m_VBox);

  /* Day, month, year spinners */

  // m_VBox.pack_start(m_HBox_NotAccelerated, Gtk::PACK_EXPAND_WIDGET, 5);

  // m_VBox_Day.pack_start(m_Label_Day);

  // //m_Button_Day.set_wrap();

  // m_VBox_Day.pack_start(m_Button_Day);

  // m_HBox_NotAccelerated.pack_start(m_VBox_Day, Gtk::PACK_EXPAND_WIDGET, 5);

  // m_VBox_Month.pack_start(m_Label_Month);

  // //m_Button_Month.set_wrap();
  // m_VBox_Month.pack_start(m_Button_Month);

  // m_HBox_NotAccelerated.pack_start(m_VBox_Month, Gtk::PACK_EXPAND_WIDGET, 5);

  // m_VBox_Year.pack_start(m_Label_Year);

  // //m_Button_Year.set_wrap();
  // m_Button_Year.set_size_request(55, -1);
  // m_VBox_Year.pack_start(m_Button_Year);

  // m_HBox_NotAccelerated.pack_start(m_VBox_Year, Gtk::PACK_EXPAND_WIDGET, 5);

  

  //Close button:
  // m_Button_Close.signal_clicked().connect( sigc::mem_fun(*this,
  //             &CalenderWindow::on_button_close) );
  // m_VBox_Main.pack_start(m_Button_Close, Gtk::PACK_SHRINK);
  m_Button_Close.signal_clicked().connect( sigc::mem_fun(*this,&CalenderWindow::on_button_close) );
  m_Button_ONE.signal_clicked().connect( sigc::bind<Glib::ustring>(sigc::mem_fun(*this,&CalenderWindow::on_button_press), "1" ));
  m_Button_TWO.signal_clicked().connect( sigc::bind<Glib::ustring>(sigc::mem_fun(*this,&CalenderWindow::on_button_press), "2" ));
  m_Button_THREE.signal_clicked().connect( sigc::bind<Glib::ustring>(sigc::mem_fun(*this,&CalenderWindow::on_button_press), "3" ));
  m_Button_FOUR.signal_clicked().connect( sigc::bind<Glib::ustring>(sigc::mem_fun(*this,&CalenderWindow::on_button_press), "4" ));
  m_Button_FIVE.signal_clicked().connect( sigc::bind<Glib::ustring>(sigc::mem_fun(*this,&CalenderWindow::on_button_press), "5" ));
  m_Button_SIX.signal_clicked().connect( sigc::bind<Glib::ustring>(sigc::mem_fun(*this,&CalenderWindow::on_button_press), "6" ));
  m_Button_SEVEN.signal_clicked().connect( sigc::bind<Glib::ustring>(sigc::mem_fun(*this,&CalenderWindow::on_button_press), "7" ));
  m_Button_EIGHT.signal_clicked().connect( sigc::bind<Glib::ustring>(sigc::mem_fun(*this,&CalenderWindow::on_button_press), "8" ));
  m_Button_NINE.signal_clicked().connect( sigc::bind<Glib::ustring>(sigc::mem_fun(*this,&CalenderWindow::on_button_press), "9" ));
  m_Button_ADD.signal_clicked().connect( sigc::bind<Glib::ustring>(sigc::mem_fun(*this,&CalenderWindow::on_button_press), "add" ));
  m_Button_EQL.signal_clicked().connect( sigc::bind<Glib::ustring>(sigc::mem_fun(*this,&CalenderWindow::on_button_press), "eql" ));
  m_Entry_Display.set_alignment(1);
  m_Entry_Display.set_text("0");
  m_Grid.attach(m_Entry_Display,1,1,5,1);
  m_Grid.attach(m_Button_ONE,1,2,1,1);
  m_Grid.attach(m_Button_TWO,2,2,1,1);
  m_Grid.attach(m_Button_THREE,3,2,1,1);
  m_Grid.attach(m_Button_FOUR,1,3,1,1);
  m_Grid.attach(m_Button_FIVE,2,3,1,1);
  m_Grid.attach(m_Button_SIX,3,3,1,1);
  m_Grid.attach(m_Button_SEVEN,1,4,1,1);
  m_Grid.attach(m_Button_EIGHT,2,4,1,1);
  m_Grid.attach(m_Button_NINE,3,4,1,1);
  m_Grid.attach(m_Button_ADD,4,2,1,1);
  m_Grid.attach(m_Button_SUB,5,2,1,1);
  m_Grid.attach(m_Button_MUL,4,3,1,1);
  m_Grid.attach(m_Button_DIV,5,3,1,1);
  m_Grid.attach(m_Button_DEC,4,4,1,1);
  m_Grid.attach(m_Button_EQL,5,4,1,1);
  m_Frame_NotAccelerated.add(m_Grid);


  show_all_children();
}

CalenderWindow::~CalenderWindow()
{
}


void CalenderWindow::on_button_close()
{
  hide();
}

void CalenderWindow::on_button_press(Glib::ustring button)
{ 
  std::string s = m_Entry_Display.get_text();
  if((std::string)(button) == "add")
  {
    m_Op = E_ADD;
    x = std::stoi(s,nullptr,10);
  }else if((std::string)(button) == "sub")
  {
    m_Op = E_SUB;
    x = std::stoi(s,nullptr,10);
  }else if((std::string)(button) == "eql")
  {
    y = std::stoi(s,nullptr,10);
    if(m_Op == E_ADD){
      int result = calculate::add(x,y);
      m_Entry_Display.set_text(std::to_string(result));
      m_Op = E_NONE;
    }      

  }
  else if(s=="0"){
      m_Entry_Display.set_text((std::string)button);
  }else{
        if(m_Op == E_ADD){
          m_Entry_Display.set_text("");
          m_Entry_Display.set_text((std::string)button);
        }else{
        s=s+(std::string)button;
        m_Entry_Display.set_text(s);
       }
  }
}

