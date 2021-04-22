---------------------------------------------------------------
-- @file	w1a03_config.lua
-- @author	Miura Yoshitaka
-- @brief	w1-3 �̐ݒ�t�@�C��
-- @data	2012/5/11
---------------------------------------------------------------

METER = 10.0

---------------------------------------------------------------

-- �������ɂ��鍂���B�����艺�Ƀv���C���[���ړ�����Ǝ��ɂ܂��B
dead_line = -500.0 * METER

-- �J�����ݒ�.
camera = {
   near = 0.1 * METER,
   far = 10000.0 * METER,
   fov = 60,
}

-- �T�[�r�X�̃��X�g.
services = {

	-- �O���A
   {
	  name = "CGlareManager",
	  params = {
		 ev = 1.0,
	  },
   },
	-- �G�b�O
   {
	  name = "EggManager",
   },
}

-- �`��ݒ�
gfx = {
	
	-- �G�t�F�N�g�ݒ�
	fx = {
		-- �J�����O
		{
			name = "CullRange",
			params = {
				-- �f�t�H���g
				range_default = 80000,
				
				-- ���i
				range_far = 100000,
			},
		},
		
		-- ���C�g�ݒ�
		{
			name = "BasicLight",
			params = {
				-- �O���[�o�����C�g(���s��)�̗L���E����
				global_light_enable = true,
				
				-- �A���r�G���g���C�g�̗L���E����
				ambient_light_enable = false,
				
				-- ���[�J�����C�g(�_�����j�̗L���E����
				local_light_enable = false,
				
				-- �J�������C�g�̗L���E����
				eye_light_enable = false,
				
				-- �J�������C�g���[�h(0:Directional 1:Omni)
				eye_light_mode = 1,
				
				-- �J�������C�g �f�B�t���[�Y(RGB)
				eye_light_diffuse = { 1.0, 1.0, 1.0, },
				
				-- �J�������C�g �X�y�L����(RGB)
				eye_light_specular = { 1.0, 1.0, 1.0, },
				
				-- �J�������C�g ���������̊J�n����
				eye_light_range_start = 0.0,
				
				-- �J�������C�g ���������̏I������
				eye_light_range_end = 100.0,
			},
		},
		
		-- �V�[���`��ݒ�
		{
			name = "Scene",
			params = {
				-- �V���̖��邳
				sky_intensity_scale = 1.0,
				
				-- �V����Y���Ǐ]��
				sky_followup_ratio_y = 1.0,
			},
		},
		
		-- ���C�g�t�B�[���h�ݒ�
		{
			name = "LightField",
			params = {
				
				-- �X�P�[�����O�^�C�v(0:KeepingLuminance 1:KeepingBrightness 2:None)
				saturation_scaling_type = 0,
				
				-- �f�[�^�����݂��Ă���������
				ignore_data = false,
				
				-- �f�t�H���g�X�V�p�x
				default_update_interval = 1,
				
				-- �I�i�̐F�␳�����Ȃ�
				no_final_adjestcolor = true,
				
				-- �C���e���V�e�B��臒l
				intensity_threshold = 0.5,
				
				-- �P�x�Œ�l
				luminance_min = 0.0,
				
				-- �P�x�ō��l
				luminance_max = 1.0,
				
				-- �P�x���Ԓl
				luminance_center = 0.5,
				
				-- �ʓx�X�P�[��
				saturation_scaling_rate = 1.0,
				
				-- �P�x�X�P�[��
				luminance_scaling_rate = 1.0,
				
				-- �f�t�H���g�l_�ォ��(RGB)
				default_color_up = {0.85, 0.85, 0.85, },
				
				-- �f�t�H���g�l_������(RGB)
				default_color_down = {1.1, 1.1, 1.1, },
				
				-- �I�t�Z�b�g�l_�ォ��(RGB)
				default_coloroffset_up = {0.0, 0.0, 0.0, },
				
				-- �I�t�Z�b�g�l_������(RGB)
				default_coloroffset_down = {0.0, 0.0, 0.0, },
			},
		},
		
		-- ���C�g�X�L���b�^�����O�Ȃ�
		{
			name = "LightScattering",
			params = {
				-- ����
				-- ���i�Ɛݒ�𕪂���Ȃ�true
				-- ������ꍇ�́Aparams_far���L�q�̂���.
				separate_enable = false,
				
				-- �L���E����
				enable = true,
				
				-- �J���[(RGB)
				color = { 0.0, 0.0, 0.0, },
				depth_scale = 0.07,
				
				--���C�g�X�L���b�^�����O
				in_scattering_scale = 300.0,
				rayleigh = 4.0,
				mie = 7.00,
				mie_power = 1.00,
				near = 50.0,
				far = 1500.0,
			},
			
			-- Far���C�g�X�L���b�^�����O�Ȃ�
			params_far = {
				-- ����
				-- �L���E����
				enable = true,
				
				-- �J���[(RGB)
				color = { 0.03, 0.13, 0.45, },
				depth_scale = 0.10,
				
				--���C�g�X�L���b�^�����O
				in_scattering_scale = 270.0,
				rayleigh = 6.50,
				mie = 5.00,
				mie_power = 1.00,
				near = 1400.0,
				far = 460000.0,
			
			},
		},
		
		-- HDR�ݒ�
		{
			name = "HDR",
			params = {
				-- �L���E����
				enable = true,
				
				-- �^�C�v(0:SimpleScale 1:ControlExposure 2:OriginalToneMap 3:CustomToneMap)
				type = 1,
				
				-- ���Ï����L��?
				adaption = true,
				
				middle_gray = 0.50,
				scale = 0.5,
				luminance_low = 0.38,
				luminance_high = 0.57,
			},
		},
		
		-- �u���[�����X�^�[�ݒ�
		{
			name = "BloomStar",
			params = {
				-- �L���E����
				enable = true,
				
				-- �O���A�^�C�v
				-- 0:Nothing 1:Natural 2:CheapLens 3:CrossScreen 4:SpectralCrossScreen 5:SnowCross
				-- 6:SpectralSnowCross 7:SunnyCross 8:SpectralSunnyCross 9:VerticalSlits 10:HorizontalSlits
				type = 1,
				
				brightpass_threshold = 0.99,
				brightpass_invscale = 8.26,
				persistent = 0.175,
				bloom_scale = 0.8,
				
				star_scale = 0.4,
			},
		},
		
		-- ��ʊE�[�x
		{
			name = "DepthofField",
			params = {
				-- �L���E����
				enable = true,
				
				focus = 54.0,
				near = 14.0,
				far = 5000.0,
				focus_range = 32.0,
				
				-- �V���ɔ�ʊE�[�x�������Ȃ�
				ignore_sky = false,
			},
		},

		-- �����ω�
		{
			name = "TimesMidifier",
			params = {
				-- �L���E����
				use_times_modifier = true,
				
				--�V���͂��̂܂܂̐F�ɂ��邩.
				ignore_sky_modifier = true,
				
				-- �e�����̎����B0����23.99�܂�
				
				time_morning = 7,
				time_day = 13,
				time_evening = 17,
				time_night = 23,
			},
			
			--��
			params_morning = {
				-- HDR
				middle_gray = 1,
				
				-- ��{�F
				basecol_r = 1,	
				basecol_g = 1,	
				basecol_b = 1,	
				
				-- ���s����
				light_r = 1,	
				light_g = 1,	
				light_b = 1,	
				
				-- �V��
				sky_intensity = 1,
				
				sky_r = 1,
				sky_g = 1,
				sky_b = 1,
				
				-- �A���r�G���g
				ambient_r = 1,
				ambient_g = 1,
				ambient_b = 1,
				
				-- ���C�g�X�L���b�^�����O
				light_scattering_r = 1,
				light_scattering_g = 1,
				light_scattering_b = 1,
			},
			

			--��
			params_day = {
				-- HDR
				middle_gray = 1,
				
				-- ��{�F
				basecol_r = 1,	
				basecol_g = 1,	
				basecol_b = 1,	
				
				-- ���s����
				light_r = 1,	
				light_g = 1,	
				light_b = 1,	
				
				-- �V��
				sky_intensity = 1,
				
				sky_r = 1,
				sky_g = 1,
				sky_b = 1,
				
				-- �A���r�G���g
				ambient_r = 1,
				ambient_g = 1,
				ambient_b = 1,
				
				-- ���C�g�X�L���b�^�����O
				light_scattering_r = 1,
				light_scattering_g = 1,
				light_scattering_b = 1,
			},
				

			--�[��
			params_evening = {
				-- HDR
				middle_gray = 1.0,
				
				-- ��{�F
				basecol_r = 1.05,	
				basecol_g = 0.85,	
				basecol_b = 0.45,	
				
				-- ���s����
				light_r = 1.2,	
				light_g = 1.1,	
				light_b = 1.0,	
				
				-- �V��
				sky_intensity = 1.15,
				
				sky_r = 1.45,
				sky_g = 0.8,
				sky_b = 0.5,
				
				-- �A���r�G���g
				ambient_r = 1.1,
				ambient_g = 0.9,
				ambient_b = 0.7,
				
				-- ���C�g�X�L���b�^�����O
				light_scattering_r = 1.0,
				light_scattering_g = 1.0,
				light_scattering_b = 1.0,
			},
												

			--��
			params_night = {
				-- HDR
				middle_gray = 1.0,
				
				-- ��{�F
				basecol_r = 0.5,	
				basecol_g = 0.9,	
				basecol_b = 1.2,	
				
				-- ���s����
				light_r = 0.2,	
				light_g = 0.4,	
				light_b = 0.7,	
				
				-- �V��
				sky_intensity = 1.0,
				
				sky_r = 0.3,
				sky_g = 0.3,
				sky_b = 0.65,
				
				-- �A���r�G���g
				ambient_r = 0.9,
				ambient_g = 1.0,
				ambient_b = 1.2,
				
				-- ���C�g�X�L���b�^�����O
				light_scattering_r = 1.0,
				light_scattering_g = 1.0,
				light_scattering_b = 1.0,
			},											
		},		
	}
}
