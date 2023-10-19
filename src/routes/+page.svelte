<script lang="ts">
	import { Client } from 'paho-mqtt';

	let client: Client;
	let currentTemp = 24.6;

	client = new Client('broker.hivemq.com', 8000, 'clientId-' + Math.random());

	client.connect({
		onSuccess: () => {
			client.subscribe('ssuniie/#');
		},
		reconnect: true
	});

	// called when a message arrives
	client.onMessageArrived = (message) => {
		currentTemp = Number(message.payloadString);
	};
</script>

<div class="text-center flex flex-col gap-16">
	<div class="flex flex-col">
		<p class="text-2xl">อุณหภูมิในขณะนี้</p>
		<h4 class="font-bold text-7xl">{currentTemp.toFixed(1)}°C</h4>
	</div>

	<small class="text-gray-400">ระบบจะทำการอ่านค่าทุก ๆ 5 วินาที</small>
</div>
