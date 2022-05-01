#include "VertexBuffer.h"

#include <exception>


namespace myengine
{
	VertexBuffer::VertexBuffer()
	{
		//Constructor for Vertex Buffer 
		glGenBuffers(1, &id);

		if (!id)
		{
			throw std::exception();
		}

		dirty = true;
		components = 0;
	}

	VertexBuffer::~VertexBuffer()
	{
		//Destructor for Vertex Buffer 
		glDeleteBuffers(1, &id);
	}

	void VertexBuffer::add(glm::vec3 value)
	{
		//Add function that adds a vector 3 vertices coordinates
		data.push_back(value.x);
		data.push_back(value.y);
		data.push_back(value.z);
		components = 3;

		dirty = true;

	}

	void VertexBuffer::add(glm::vec4 value)
	{
		//Add function that adds a vector 4 vertices coordinates
		data.push_back(value.x);
		data.push_back(value.y);
		data.push_back(value.z);
		data.push_back(value.w);
		components = 4;

		dirty = true;
	}

	GLuint VertexBuffer::getId()
	{
		//Returns the id and binds the buffer 
		if (dirty)
		{
			glBindBuffer(GL_ARRAY_BUFFER, id);



			//upload a copy of the data from memory into the new VBO
			glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(data.at(0)), &data.at(0),
				GL_STATIC_DRAW);

			// reset the state
			glBindBuffer(GL_ARRAY_BUFFER, 0);

			dirty = false;
		}

		return id;
	}

	int VertexBuffer::getComponents()
	{
		//Returns the components 
		return components;
	}

}