
#include "block.h"


Block::Block(const ShapeType& shape)
    : shape_index_(0),
      position_(Position(3, 0)),
      shape_type_(shape),
      is_focusing_(false)
{
}


const Block::ShapeType Block::getRandomShape()
{
  using namespace std::chrono;
  auto now = high_resolution_clock::now();
  auto ns = duration_cast<milliseconds>(now.time_since_epoch());

  auto fractional_seconds = ns.count() % shape_type_count_;
  // TODO give more Randomness
  switch (fractional_seconds)
  {
    case 0: return Block::I;
    case 1: return Block::J;
    case 2: return Block::L;
    case 3: return Block::O;
    case 4: return Block::S;
    case 5: return Block::T;
    case 6: return Block::Z;
    default: return Block::EMPTY;
  }
}


void Block::rotateBlock(Rotation direction)
{
  if (direction == Rotation::CW)
    shape_index_.rotateCw();
  else if (direction == Rotation::ACW)
    shape_index_.rotateAcw();
}

void Block::moveBlock(const Shifting direction)
{
  if (direction == Shifting::RIGHT)
    position_.x_++;
  else if (direction == Shifting::LEFT)
    position_.x_--;
  else if (direction == Shifting::UP)
    position_.y_--;
  else if (direction == Shifting::DOWN)
    position_.y_++;
}


const Position& Block::getPosition() const
{
  return position_;
}

const Shape& Block::getShape() const
{
  auto& shape_list = shpae_list_map_.find(shape_type_)->second;
  auto& shape = shape_list.at(shape_index_.getIndex());
  return shape;
}

const Block::ShapeType& Block::getShapeType() const
{
  return shape_type_;
}

const int Block::getContainerWidth() const
{
  return getShape().at(0).size();
}

const int Block::getContainerHeight() const
{
  return getShape().size();
}


void Block::setPosition(Position&& position)
{
  position_ = position;
}

void Block::setPosition(short int x, short int y)
{
  position_.x_ = x;
  position_.y_ = y;
}


void Block::printStatus() const
{
  if (shape_type_ ==  EMPTY) std::cout << "Shape type: Empty" << std::endl;
  else if (shape_type_ == I) std::cout << "Shape type: I" << std::endl;
  else if (shape_type_ == J) std::cout << "Shape type: J" << std::endl;
  else if (shape_type_ == L) std::cout << "Shape type: L" << std::endl;
  else if (shape_type_ == O) std::cout << "Shape type: O" << std::endl;
  else if (shape_type_ == I) std::cout << "Shape type: I" << std::endl;
  else if (shape_type_ == S) std::cout << "Shape type: S" << std::endl;
  else if (shape_type_ == T) std::cout << "Shape type: T" << std::endl;
  else if (shape_type_ == Z) std::cout << "Shape type: Z" << std::endl;
  std::cout << "Shape index: " << shape_index_.getIndex() << std::endl;
  std::cout << "X:" << position_.x_ << " Y: " << position_.y_ << std::endl;
  std::cout << std::endl;
}