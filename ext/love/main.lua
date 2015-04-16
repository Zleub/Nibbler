function love.load()
	t = {}
	height = love.window.getHeight()
end

function love.update(dt)
	l = io.read('*l')
	table.insert(t, l);
	if #t * 12 > height then
		table.remove(t, 1)
	end
end

function love.draw()
	i = 0;
	for k,v in ipairs(t) do
		love.graphics.print(v, 0, i * 12)
		i = i + 1;
	end
end
