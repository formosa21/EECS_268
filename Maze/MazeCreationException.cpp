#include "MazeCreationException.h"

MazeCreationException::MazeCreationException(const char* message) : std::runtime_error(message)
{
}
