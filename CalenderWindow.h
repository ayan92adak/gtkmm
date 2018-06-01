#include <gtkmm.h>

class CalenderWindow : public Gtk::Window
{
public:
  CalenderWindow();
  virtual ~CalenderWindow();

protected:
  //Signal handlers:
  void on_checkbutton_snap();
  void on_checkbutton_numeric();
  void on_spinbutton_digits_changed();
  void on_button_close();

  enum enumValueFormats
  {
    VALUE_FORMAT_INT,
    VALUE_FORMAT_FLOAT
  };
  void on_button_getvalue(enumValueFormats display);

  //Child widgets:
  Gtk::Frame m_Frame_NotAccelerated;
  Gtk::Box m_HBox_NotAccelerated;
  Gtk::Box m_VBox_Main, m_VBox, m_VBox_Day, m_VBox_Month, m_VBox_Year;
  Gtk::Label m_Label_Day, m_Label_Month, m_Label_Year;
  Glib::RefPtr<Gtk::Adjustment> m_adjustment_day, m_adjustment_month, m_adjustment_year;
  Gtk::SpinButton m_SpinButton_Day, m_SpinButton_Month, m_SpinButton_Year;
  Gtk::CheckButton m_CheckButton_Snap, m_CheckButton_Numeric;
  Gtk::Button m_Button_Close;
};