# IOBuffer (Input / Output Buffer)
## About 
This is a general purpose, multi instance, FIFO buffer.
Using the IO Dispatcher, the user can add multiple IO buffers.
Each IO Buffer uses a single FIFO queue of a specific data type. Write adds to the front and Read pops the queue.

Currently, this has only been tested with int, float, std::string and classes.

## Usage
Include this IOBuffer folder in your project file (VS .sln, CMakeLists.txt, etc.)
and make sure all files (except the README.md file) are included in the build process.

The class IODispatcher should be instantiated by the main application, e.g.:
```
#include "IODispatcher.h"

CIODispatcher dispatcher;
std::shared_ptr<CIODispatcher> m_SharedPtrToDispatcher = std::make_shared<CIODispatcher>();
std::unique_ptr<CIODispatcher> m_UniquePtrToDispatcher = std::make_unique<CIODispatcher>();
```

For buffer operations, refer to the function descriptions located in IODispatcher.h :
```
int NumberOfBuffers();
int NumberOfEntriesPerBuffer(int bufferID);
bool Write(const int bufferID, const T& t)
bool Read(int bufferID, T& t){
bool RemoveBuffer(int bufferID)
```

BufferID is used for most API calls. 
This will need to be created by the main application and each IOBuffer will need a unique ID.
The Write callback will add a new IOBuffer if the bufferID has not been used before.
The Write callback will write to the queue of the existing IOBuffer if the bufferID has already been used.

The Read and Write callbacks will handle type checking. The the data type does not match then there will be
an error message and the request will be ignored.

## Notes
There is no 'add buffer' callback. 
Several examples of usage can be found in the Test folder (../../Test/IOBuffer/src/main.cpp).

