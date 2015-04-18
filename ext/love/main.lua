function love.load()
	socket = require("socket")

	t = {}
	time = 0
	height = love.window.getHeight()
	print("load")

	s = socket.connect("127.0.0.1", 4242)
	if s == nil then love.event.quit() end
	-- s:settimeout(1)
	timeout = 0.1
	time = 0
end

function love.update(dt)
	time = time + dt
	print(time)
	print("update")
	local keys = {}

	keys.up = love.keyboard.isDown('up')
	keys.down = love.keyboard.isDown('down')
	keys.left = love.keyboard.isDown('left')
	keys.right = love.keyboard.isDown('right')

	if time > timeout then
		l = s:receive('*l')
		table.insert(t, l)
		if #t * 12 > height then
			table.remove(t, 1)
		end
		time = 0
	end

	local msg = ' '
	for k,v in pairs(keys) do
		if v then
			msg = msg..k..' '
		end
	end
	s:send(msg)
end

function love.draw()
	i = 0
	for k,v in ipairs(t) do
		love.graphics.print(v, 0, i * 12)
		i = i + 1
	end
end
