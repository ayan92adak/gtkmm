#include <gtkmm.h>

typedef enum
  {
    E_NONE,
    E_ADD,
    E_SUB,
    E_MUL,
    E_DIV
  } E_Operatiion;

class CalenderWindow : public Gtk::Window
{
private:
  int x,y;
public:
  CalenderWindow();
  virtual ~CalenderWindow();


protected:
  //Signal handlers:
  void on_checkbutton_snap();
  void on_checkbutton_numeric();
  void on_spinbutton_digits_changed();
  void on_button_close();
  void on_button_press(Glib::ustring);
  //void on_button_getvalue(enumValueFormats display);
  E_Operatiion m_Op;


  //Child widgets:
  Gtk::Frame m_Frame_NotAccelerated;
  Gtk::Box m_HBox_NotAccelerated;
  Gtk::Box m_VBox_Main, m_VBox, m_VBox_Day, m_VBox_Month, m_VBox_Year;
  Gtk::Label m_Label_Day, m_Label_Month, m_Label_Year;
  Glib::RefPtr<Gtk::Adjustment> m_adjustment_day, m_adjustment_month, m_adjustment_year;
  Gtk::Button m_Button_ONE, m_Button_TWO, m_Button_THREE;
  Gtk::Button m_Button_FOUR, m_Button_FIVE, m_Button_SIX;
  Gtk::Button m_Button_SEVEN, m_Button_EIGHT, m_Button_NINE, m_Button_ZERO;
  Gtk::Button m_Button_ADD, m_Button_SUB, m_Button_MUL, m_Button_DIV;
  Gtk::Button m_Button_DEC, m_Button_EQL;
  Gtk::CheckButton m_CheckButton_Snap, m_CheckButton_Numeric;
  Gtk::Button m_Button_Close;
  Gtk::Grid m_Grid;
  Gtk::Entry m_Entry_Display;
};