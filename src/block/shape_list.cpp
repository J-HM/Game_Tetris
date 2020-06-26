#include "block.hpp"

const std::map<Block::ShapeType, const ShapeList&> Block::shpae_list_map_ =
{
  {Block::EMPTY, Block::empty_shape_list_},
  {Block::I, Block::i_shape_list_},
  {Block::J, Block::j_shape_list_},
  {Block::L, Block::l_shape_list_},
  {Block::O, Block::o_shape_list_},
  {Block::S, Block::s_shape_list_},
  {Block::T, Block::t_shape_list_},
  {Block::Z, Block::z_shape_list_}
};

const ShapeList Block::empty_shape_list_ =
{
  {
    {0}
  }
};

const ShapeList Block::i_shape_list_ =
{
  {
    {0, 0, 0, 0},
    {1, 1, 1, 1},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
  },
  {
    {0, 0, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 1, 0}
  },
  {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {1, 1, 1, 1},
    {0, 0, 0, 0}
  },
  {
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 0, 0}
  }
};

const ShapeList Block::j_shape_list_ =
{
  {
    {1, 0, 0},
    {1, 1, 1},
    {0, 0, 0}
  },
  {
    {0, 1, 1},
    {0, 1, 0},
    {0, 1, 0},
  },
  {
    {0, 0, 0},
    {1, 1, 1},
    {0, 0, 1},
  },
  {
    {0, 1, 0},
    {0, 1, 0},
    {1, 1, 0},
  }
};

const ShapeList Block::l_shape_list_ =
{
  {
    {0, 0, 1},
    {1, 1, 1},
    {0, 0, 0}
  },
  {
    {0, 1, 0},
    {0, 1, 0},
    {0, 1, 1},
  },
  {
    {0, 0, 0},
    {1, 1, 1},
    {1, 0, 0},
  },
  {
    {1, 1, 0},
    {0, 1, 0},
    {0, 1, 0},
  }
};

const ShapeList Block::o_shape_list_ =
{
  {
    {0, 1, 1, 0},
    {0, 1, 1, 0},
    {0, 0, 0, 0},
  },
  {
    {0, 1, 1, 0},
    {0, 1, 1, 0},
    {0, 0, 0, 0},
  },
  {
    {0, 1, 1, 0},
    {0, 1, 1, 0},
    {0, 0, 0, 0},
  },
  {
    {0, 1, 1, 0},
    {0, 1, 1, 0},
    {0, 0, 0, 0},
  }
};

const ShapeList Block::s_shape_list_ =
{
  {
    {0, 1, 1},
    {1, 1, 0},
    {0, 0, 0},
  },
  {
    {0, 1, 0},
    {0, 1, 1},
    {0, 0, 1},
  },
  {
    {0, 0, 0},
    {0, 1, 1},
    {1, 1, 0},
  },
  {
    {1, 0, 0},
    {1, 1, 0},
    {0, 1, 0},
  }
};

const ShapeList Block::t_shape_list_ =
{
  {
    {0, 1, 0},
    {1, 1, 1},
    {0, 0, 0},
  },
  {
    {0, 1, 0},
    {0, 1, 1},
    {0, 1, 0},
  },
  {
    {0, 0, 0},
    {1, 1, 1},
    {0, 1, 0},
  },
  {
    {0, 1, 0},
    {1, 1, 0},
    {0, 1, 0},
  }
};

const ShapeList Block::z_shape_list_ =
{
  {
    {1, 1, 0},
    {0, 1, 1},
    {0, 0, 0},
  },
  {
    {0, 0, 1},
    {0, 1, 1},
    {0, 1, 0},
  },
  {
    {0, 0, 0},
    {1, 1, 0},
    {0, 1, 1},
  },
  {
    {0, 1, 0},
    {1, 1, 0},
    {1, 0, 0},
  }
};
