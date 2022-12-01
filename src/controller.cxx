#include "controller.hxx"

Controller::Controller()
        :
        view_(model_),
        first_click{0,0},
        second_click{0,0},
        mouse{0,0}
{ }

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.update_mouse(mouse);
    view_.draw(set);
}

void Controller::on_mouse_down(
        ge211::events::Mouse_button,
        ge211::geometry::Posn<int> pos)
{
    ge211::geometry::Posn<int> real_pos = view_.screen_to_board(pos);
    try{
        model_.play_move(real_pos);
    }
    catch(...){}
}

View::Dimensions Controller::initial_window_dimensions() const
{
    return view_.initial_window_dimensions();
}

std::string Controller::initial_window_title() const
{
    return view_.initial_window_title();
}

void Controller::on_mouse_move(ge211::geometry::Posn<int> pos)
{
    mouse = pos;
}
