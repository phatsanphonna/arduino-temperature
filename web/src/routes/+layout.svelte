<script>
	import Navbar from '$lib/components/svelte/Navbar.svelte';
	import '../app.postcss';
</script>

<svelte:head>
	<link rel="preconnect" href="https://fonts.googleapis.com" />
	<link rel="preconnect" href="https://fonts.gstatic.com" crossorigin="anonymous" />
	<link
		href="https://fonts.googleapis.com/css2?family=IBM+Plex+Sans+Thai:wght@100;200;300;400;500;600;700&display=swap"
		rel="stylesheet"
	/>
</svelte:head>

<Navbar />

<main
	class="w-full min-height container mx-auto flex flex-col gap-8 justify-center items-center py-12"
>
	<slot />
</main>

<style>
	.min-height {
		min-height: calc(100vh - 4rem);
	}
</style>
