#include "main_window.h"

Main_window::~Main_window(){}
Main_window::Main_window(){
  set_default_size(400,200);

	Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL,0));
	add(*vbox);

  //menu bar at the top
  Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
	vbox->pack_start(*menubar,Gtk::PACK_SHRINK,0);

  //file dropdown menu
	Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File",true));
	menubar->append(*menuitem_file);
	Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
	menuitem_file->set_submenu(*filemenu);

  /*  TODO
      append NEW
      append OPEN
      append SAVE
      append SAVE AS

  */

  //append quit to the file menu
	Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit",true));
	menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
	filemenu->append(*menuitem_quit);

  //add dropdown menu
  Gtk::MenuItem *menuitem_add = Gtk::manage(new Gtk::MenuItem("_Add",true));
  menubar->append(*menuitem_add);
  Gtk::Menu *add_menu = Gtk::manage(new Gtk::Menu());
  menuitem_add->set_submenu(*add_menu);

  //append items to add menu
  Gtk::MenuItem *m_items = Gtk::manage(new Gtk::MenuItem("_Items",true));
  m_items->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_add_items_click));
  add_menu->append(*m_items);

  /*TODO
    append CUSTOMER
    append SERVER
  */

  //create serving dropdown(Make a order button later)(Gtk::Toolbar)
  Gtk::MenuItem *menuitem_create = Gtk::manage(new Gtk::MenuItem("_Create",true));
  menubar->append(*menuitem_create);
  Gtk::Menu *add_create_menu = Gtk::manage(new Gtk::Menu());
  menuitem_create->set_submenu(*add_create_menu);

  //append create to serving menu
  Gtk::MenuItem *serving = Gtk::manage(new Gtk::MenuItem("_Serving",true));
  serving->signal_activate().connect(sigc::mem_fun(*this,&Main_window::on_create_serving_click));
  add_create_menu->append(*serving);


  //TODO EDIT REPORT ABOUT dropdown menu

  //TOOLBAR
  // Add a toolbar to the vertical box below the menu
  Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
  vbox->add(*toolbar);

  //new items button
  Gtk::ToolButton *new_item_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::ADD));
  new_item_button->set_tooltip_markup("Add new items");
  new_item_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_add_items_click));
  toolbar->append(*new_item_button);

  //create serving button /create order button
  Gtk::Image *create_order_image = Gtk::manage(new Gtk::Image("create_serving.png"));
  Gtk::ToolButton *create_order = Gtk::manage(new Gtk::ToolButton(*create_order_image));
  create_order->set_tooltip_markup("Create Order");
  create_order->signal_clicked().connect(sigc::mem_fun(*this,
  &Main_window::on_create_serving_click));
  toolbar->append(*create_order);

  //list serving components button
  Gtk::ToolButton *list_serving= Gtk::manage(new Gtk::ToolButton(Gtk::Stock::INDEX));
  list_serving->set_tooltip_markup("List Serving");
  list_serving->signal_clicked().connect(sigc::mem_fun(*this,
  &Main_window::on_list_serving_click));
  toolbar->append(*list_serving);

  //seperate
  Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
  sep->set_expand(true);  // The expanding sep forces the Quit button to the right
  toolbar->append(*sep);

  //exit button
  Gtk::ToolButton *quit_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
  quit_button->set_tooltip_markup("Exit MICE");
  quit_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
  toolbar->append(*quit_button);


  vbox->show_all();
}

void Main_window::on_list_serving_click(){controller.list_serving_dialog();}
void Main_window::on_create_serving_click(){controller.create_serving_dialog();}
void Main_window::on_quit_click(){hide();}
void Main_window::on_add_items_click(){controller.add_dialog();}