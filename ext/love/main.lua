function love.load()
	socket = require("socket")

	t = {}
	time = 0
	height = love.window.getHeight()
	print("load")

	s = socket.connect("127.0.0.1", 4242)
	if s == nil then love.event.quit() end
	s:settimeout(1)
end

function love.update(dt)
	print("update")
	-- l = io.read('*l')
	l = s:receive('*l')
	table.insert(t, l)
	if #t * 12 > height then
		table.remove(t, 1)
	end
	time = time + dt

	s:send('EVENT COLLECTION')
end

function love.draw()
	i = 0
	for k,v in ipairs(t) do
		love.graphics.print(v, 0, i * 12)
		i = i + 1
	end
end
